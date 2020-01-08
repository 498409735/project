
#include "admin.h"
#include "lottery.h"
#include "user.h"
/* ********************************************************
@parameter: aticket_t*head 链表头结点
@return:	NONE
@explain:	释放已经开票空间，防止内存泄漏							
*/
void free_aticket(aticket_t*head){
	aticket_t*p = head;
	while(p->next!=head){
		
		p = p->next;
		free(p->prev);		
	}
	free(p);
}
/* ********************************************************
@parameter: aticket_t*uthead链表头结点
@return:	NONE
@explain:	删除最新一期发行彩票							
*/
void remove_aticket(aticket_t*athead,unsigned int* aticket_len){
	aticket_t*at = athead;
	

	while(at->next!=athead){
		at = at->next;
	}
	at->prev->next = at->next;
	at->next->prev = at->prev;
	free(at);
	(*aticket_len)--;
	printf("删除发行彩票成功\n");	
}
/* ************************************************
@parameter:	aticket_t*head 双向链表头结点
			unsigned int* aticket_len 链表长度,可修改
@return:	NONE
@explain:	发布新的彩票
 */
void publish_admin(aticket_t*head,unsigned int* aticket_len){
	int price_tmp;
	int jackkpot_tmp;
	aticket_t*at		= head;
	aticket_t at_tmp 	= {0};
	while(at->next!= head){
		at = at->next;
	}
	if(at->issue>0&&at->open_state!=true){
		printf("上期彩票尚未开奖,禁止发行新一期彩票\n");
		return;
	}
	printf("请输入本期彩票每注单价\n");
	scanf("%d",&price_tmp);
	while(getchar()!=10);
	
	price_tmp 		= (price_tmp<1)?1:price_tmp;	//彩票金额最小为1，防止输入错误
	at_tmp.price	= price_tmp;
	
	printf("请输入本期彩票奖池金额\n");
	scanf("%d",&jackkpot_tmp);
	while(getchar()!=10);

	jackkpot_tmp = (jackkpot_tmp<50000)?50000:jackkpot_tmp; 
	at_tmp.jackpot			= at->jackpot+jackkpot_tmp;
	
	at_tmp.issue 			= at->issue+1;
	memset(at_tmp.win_num,0,sizeof(at_tmp.win_num));
	if(at_tmp.price<1||at_tmp.price<1){
		printf("发布新彩票失败,返回\n");
		return;
	}
	aticket_t* new_aticket	= calloc(1,sizeof(aticket_t));
	memcpy(new_aticket,&at_tmp,sizeof(aticket_t));
	
	new_aticket->prev 		= at;
	new_aticket->next 		= at->next;	
	at->next = new_aticket;
	(*aticket_len)++;
	printf("****本期彩票发行成功!!!\n");
	printf("****期号为%d,每注单价%d元,目前奖池金额%d元\n",new_aticket->issue,new_aticket->price,new_aticket->jackpot);
	// p = p->next;
}
  /* ************************************************
@parameter:	aticket_t*head 发布彩票双向循环链表头结点
			unsigned int user_len 链表当前长度
@return:	NONE
@explain:	打印发行彩票信息
 */
void print_all_aticket(aticket_t*head){

	aticket_t*p = head->next;

	printf("************彩票发行记录******************\n");
	printf("期号\t单价\t开奖状态\t开奖号码\t售出总数\t奖池金额\n");
	 while(p!=head){
		 printf("%2d\t%2d\t%s\t\t%hd-%hd-%hd-%hd\t%d\t\t%d\n",p->issue,p->price,
				(p->open_state!=false)?"YES":"NO",p->win_num[0],p->win_num[1],p->win_num[2],p->win_num[3],
				p->selle_count,p->jackpot);
		 
		 p = p->next;
	 }
}
/* ************************************************
@parameter:	aticket_t*head 发布彩票双向循环链表头结点
			unsigned int user_len 链表当前长度
@return:	NONE
@explain:	保存已发布彩票信息
 */
 void save_aticket(aticket_t*head){
	FILE* fp = fopen("./doc/published_ticket.txt","w");
	if(fp==NULL){
		 printf("打开published_ticket.txt失败,返回\n");
		 return;
	 }
	 aticket_t*p = head->next;
	 
	 while(p!=head){
		 fwrite(p,1,sizeof(aticket_t),fp);
		 p = p->next;
	 }
	 fclose(fp);
 }
  /* ************************************************
@parameter:	aticket_t*head 发布彩票双向循环链表头结点
			unsigned int user_len 链表当前长度
@return:	NONE
@explain:	加载发布的彩票信息
 */
void load_aticket(aticket_t*head,unsigned int* aticket_len){
	 FILE* fp = fopen("./doc/published_ticket.txt","r");
	 if(fp==NULL){
		 printf("打开published_ticket.txt失败,返回\n");
		 return;
	 }
	 aticket_t*p = head;
	 
	 int res ;
	 while(1){
		aticket_t* data = malloc(sizeof(aticket_t));
		memset(data,0,sizeof(aticket_t));
		res = fread(data,1,sizeof(aticket_t),fp);
		if(res==0){
			free(data);
			break;
		}
		data->prev = p;
		data->next = p->next;
		p->next = data;
		p = p->next;
		(*aticket_len)++;
	 }
	 fclose(fp);
}
/* ************************************************
@parameter:	short* arr 开奖号码保存数组指针
@return:	int 为今后修改做准备
@explain:	自动开奖号码生成
 */
int auto_drawing(short* arr){
	
	int i,j,data;
	// short tmp[4];
	struct termios org_opts;
	struct termios new_opts;
	tcgetattr(STDIN_FILENO,&org_opts);
	new_opts = org_opts;
	new_opts.c_lflag &=~(ICANON|ECHO|ECHOE|ECHOK|ECHONL|ECHOPRT|ECHOKE|ICRNL);
	tcsetattr(STDIN_FILENO,TCSANOW,&new_opts);
	printf("开始摇奖\r\n");
	// fflush(stdout);
	// while(getch()!=10);
	srand(time(0));
	printf("__-__-__-__");
	printf("\033[11D");
	fflush(stdout);
	data = 1;
	for(j=0;j<4;j++){
		for(i=0;i<1000;i++){
			
			data = rand()%100;
			printf("%02d",data);
			fflush(stdout);		
			printf("\033[2D");			
			usleep(1000);
		}
		arr[j] = data;
		printf("\033[3C");
		fflush(stdout);
	}
	tcsetattr(STDIN_FILENO,TCSANOW,&org_opts);
	printf("开奖结束,本次开奖号码为\n");
	printf("%d-%d-%d-%d\n",arr[0],arr[1],arr[2],arr[3]);
	return 0;
	
}
/* ************************************************
@parameter:	short* arr传入存放开票号码数组指针
@return:	成功返回0;失败-1
@explain:	手动开票
 */
int manuel_drawing(short* arr){
	short tmp[4];

	int i;
	
	for(i=0;i<sizeof(tmp);i++){
		printf("请依次输入4组个非零两位数号码\n");
		scanf("%hd",&tmp[i]);
		while(getchar()!=10);
	}
	memcpy(arr,tmp,sizeof(tmp));
	return 0;
} 
/* ************************************************
@parameter:	short* arr开奖号码保存数组指针
@return:	成功返回0;失败-1
@explain:	开奖选择
 */
int drawing_select(short* arr){
	int ch;
	
	while(1){
		printf("自动开奖请按1,手动开奖请按2,返回请按0\n");
		scanf("%d",&ch);
		while(getchar()!=10);
		switch(ch){
			case 1:
				if(auto_drawing(arr)<0){
					printf("开奖失败,返回\n");
					return -1;
				}else return 0;	
			break;
			case 2:
				if(manuel_drawing(arr)<0){
					printf("开奖失败,返回\n");
					return -1;
				}else return 0;
			break;
			case 0:
				printf("取消开奖,返回\n");
				return -1;
			break;
			default:
				printf("无效输入,请重新输入\n");
			break;			
		}
		
	}
}
/* ************************************************
@parameter:	aticket_t*head 开奖彩票双向循环链表头结点
			unsigned int user_len 链表当前长度
@return:	NONE
@explain:	开奖彩票，将本期号码填充并公布
 */
void lottery_drawing(aticket_t*head,uticket_t* uthead,user_t*uhead){
	aticket_t*at = head;
	uticket_t*ut = uthead->next;
	unsigned int cnt=0;
	int winner_cnt=0;
	int i;
	while(at->next!=head){
		at = at->next;
	}
	if(at->issue<1||at->open_state!=false){
		printf("新一期彩票尚未发行,禁止开奖\n");
		return;
	}
	if(drawing_select(at->win_num)<0){
		return;
	}
	
	while(ut!=uthead){						//计算售出总数
		if(at->issue==ut->issue){
			cnt+= ut->bet_cnt;
		}
		ut = ut->next;
	}	
	at->open_state		= true;			//开奖状态
	at->selle_count 	= cnt;			//售出总数
	at->jackpot			= at->jackpot+cnt*at->price;
	

	printf("本次彩票开奖奖池金额%d,共售出%d注\n开奖号码为%hd-%hd-%hd-%hd\n",at->jackpot,at->selle_count,
			at->win_num[0],at->win_num[1],at->win_num[2],at->win_num[3]);
	ut = uthead->next;		
	while(ut!=uthead){
		if(at->issue == ut->issue){
			for(i=0;i<5;i++){
				ut->user_state = ut->user_state<<1;//左移一位,高位->低位表示第几注中奖
				if(at->win_num[0]==ut->bet_num[i][0]&&at->win_num[1]==ut->bet_num[i][1]
				&&at->win_num[2]==ut->bet_num[i][2]&&at->win_num[3]==ut->bet_num[i][3]){
				winner_cnt++;
				ut->user_state+=1;
				}				
			}
			if(ut->user_state==0){
				ut->user_state = NOT_WIN;		//未中奖
			}
		}
		ut = ut->next;
	}
	if(winner_cnt==0){
		printf("没有任何人中奖\n");
		return;
	}
	int tmp = at->jackpot/winner_cnt;
	at->jackpot = 0;
	
	ut = uthead->next;
	// short state_tmp = ut->user_state;
	while(ut!=uthead){
		if(at->issue == ut->issue){
			for(i=0;i<5;i++){
				// ut->user_state =ut->user_state<<1;//左移一位,高位->低位表示第几注中奖
				if(at->win_num[0]==ut->bet_num[i][0]&&at->win_num[1]==ut->bet_num[i][1]
				&&at->win_num[2]==ut->bet_num[i][2]&&at->win_num[3]==ut->bet_num[i][3]){
					ut->win_bonus+=tmp;
				}				
			}
		}
		user_t* tar = find_user(uhead,ut->name);
		if(tar!=NULL){
			tar->balance = tar->balance+ut->win_bonus;
			
		}
		ut = ut->next;
	}
	printf("本次彩票共%d注号码中奖\n",winner_cnt);
	
}
/* ************************************************
@parameter:	aticket_t*ahead 发行彩票双向循环链表
			user_t*head 用户单向不循环链表头结点
			unsigned int aticket_len 链表当前长度
@return:	NONE
@explain:	根据余额查询用户信息
 */
void browse_user(user_t*uhead){
	user_t* p = uhead->next;
	int total=0,count =0,value;
	printf("浏览余额不小于某值的用户信息,请输入此值\n");
	scanf("%d",&value);
	while(getchar()!=10);
	printf("\t序号****姓名****余额****\n");
	while(p!=NULL){
		total++;
		if(p->balance>=value){
			count++;
			printf("\t%d\t%s\t%d\n",count,p->name,p->balance);
		}
		if(p->next==NULL)break;
		p = p->next;
	}
	printf("总共%d位彩民,以上%d位为余额大于%d元的彩民\n",total,count,value);
	printf("\n\n");
}
/* ************************************************
@parameter:	aticket_t*ahead 发行彩票双向循环链表
			user_t*head 用户单向不循环链表头结点
			unsigned int aticket_len 链表当前长度
@return:	NONE
@explain:	根据彩民余额排序显示
 */
void user_bubble(user_t*uhead){
	 user_t* p = uhead;
	 user_t* q = uhead;
	 user_t tmp = {0};
	 while(p->next!=NULL){
		 q = uhead;
		 while(q->next!=NULL){
			 if(q->balance > q->next->balance){
				strcpy(tmp.name,q->name);
				strcpy(tmp.pswd,q->pswd);
				tmp.balance = q->balance;
				
				strcpy(q->name,q->next->name);
				strcpy(q->pswd,q->next->pswd);
				q->balance = q->next->balance;
				
				strcpy(q->next->name,tmp.name);
				strcpy(q->next->pswd,tmp.pswd);
				q->next->balance = tmp.balance;			
			}
			q = q->next;
		 }
		p = p->next;
	 }
 }
/* ************************************************
@parameter:	aticket_t*ahead 发行彩票双向循环链表
			user_t*head 用户单向不循环链表头结点
			unsigned int aticket_len 链表当前长度
@return:	NONE
@explain:	管理员操作
 */
void admin_action(aticket_t*ahead,unsigned int* aticket_len,uticket_t* uthead,user_t*uhead){
	int ch;
	 while(1){
		printf("管理员操作:\n");
		printf("1:\t发行彩票\n");
		printf("2:\t查询彩民余额信息\n");
		printf("3:\t排序显示彩民\n");
		printf("4:\t保存\n");
		printf("0:\t返回\n");
		scanf("%d",&ch);
		while(getchar()!=10);
		switch(ch){
			case 1:
				publish_admin(ahead,aticket_len);
			break;
			case 2:
				browse_user(uhead);
			break;
			case 3:
				user_bubble(uhead);
				print_all_user(uhead);
			break;
			case 4:
				save_uticket(uthead);
				save_aticket(ahead);
				save_user(uhead);
				printf("保存成功\n");
			break;
			case 0:
				return;
			break;
			default:
				printf("无效输入，请重新输入\n");
			break;
		} 
	 }
}
/* ************************************************
@parameter:	aticket_t*athead 发行彩票双向循环链表
			user_t*head 用户单向不循环链表头结点
			unsigned int aticket_len 链表当前长度
@return:	NONE
@explain:	管理员操作
 */
void worker_action(aticket_t*athead,unsigned int* aticket_len,uticket_t* uthead,user_t*uhead){
	int ch;
	 while(1){
		printf("********管理员操作:\n");
		printf("1:\t开奖\n");
		printf("2:\t查询历史发行\n");
		printf("3:\t删除最新一期发行彩票\n");
		printf("0:\t返回\n");
		scanf("%d",&ch);
		while(getchar()!=10);
		switch(ch){
			case 1:
				lottery_drawing(athead,uthead,uhead);
			break;
			case 2:
				print_all_aticket(athead);
			break;
			case 3:
				remove_aticket(athead,aticket_len);	//为调试使用
			break;			
			case 0:
				return;
			break;
			default:
				printf("无效输入，请重新输入\n");
			break;
		} 
	 }
	
	
}













