#include "lottery.h"
#include "user.h"
#include "admin.h"

char admin[] = "admin";
char adminpswd[] = "12345";
char worker[] = "worker";
char workerpswd[] = "12345";

int getch()  
{  
		int c=0;  
		struct termios org_opts, new_opts;  
		int res=0;  

		res=tcgetattr(STDIN_FILENO, &org_opts);  
		assert(res==0);  
		memcpy(&new_opts, &org_opts, sizeof(new_opts));  
		new_opts.c_lflag &= ~(ICANON | ECHO | ECHOE | ECHOK | ECHONL | ECHOPRT     | ECHOKE | ICRNL);  
		tcsetattr(STDIN_FILENO, TCSANOW, &new_opts);  
		c=getchar();  
		res=tcsetattr(STDIN_FILENO, TCSANOW, &org_opts);  
		assert(res==0);  
		return c;  
} 
int getPassword(char *pcPWD)
{
	int ch=0;

	int i=0;

	for(i=0;i<20;)
	{
		ch=getch();
		if(ch==-1)//当无键入时，跳出当前循环继续下一个循环
		{
				continue;
		}
		//127在键盘上是delete  8代表退格键backspace
		if((ch == 127 || ch == 8) && i>0)//当有键入时，按键delete或backspace时，删除一位
		{
				putchar('\b');	//这里是删除一个，通过输出回撤符 /b，回撤一格，
				putchar(' ');	//再显示空格符把刚才的*给盖住，
				putchar('\b');	//然后再 回撤一格等待录入。
				i--;			//减少一位
		}else if(ch == 27){
			return -1;
		}
		//10在键盘上代表换行(LF)，13代表回车(CR)
		//3.在不同平台，输入回车，getch()将返回不同数值，而getchar()统一返回10(即\n)
		//1)windows平台下ENTER键会产生两个转义字符 \r\n，因此getch返回13(\r)。
		//2)unix、 linux系统中ENTER键只产生 \n ，因此getch返回10(\n)。
		//3)MAC OS中ENTER键将产生 \r ，因此getch返回13(\r)。
		else if(ch==10 || ch == 13)//当键入的为换行时
		{
				pcPWD[i]='\0';//将字符串以'\0'结尾
				putchar('\n');
				return 0;
		}
		else if(i==0&&(ch==127 ||ch == 8))//当无键入时，按键delete或backspace时，产生警报
		{
				printf("\a");
		}
		else if(i<19)//当键入的数少于19位时每键入一个数打印一个星号覆盖
		{
				pcPWD[i]=(char)ch;
				putchar('*');
				i++;
		}
		else//当键入的数超过19位时，再次键入产生响铃
		{
				printf("\a");//响铃
		}
	}
	return -1;
}
int getstring(char* str,unsigned int len){
	int pos;
	fgets(str,len,stdin);
	pos = strlen(str);
	if(str[pos-1]==10){
		str[pos-1]=0;
		return pos-1;
	}
	return pos;
}
int identifyCode(void)
{
	char array[100]="ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789";
	char a[5]="";
	char b[5]="";

	while(1)
	{
		//得到验证码
		srand(time(NULL));
		a[0] = array[rand()%26];
		a[1] = array[rand()%26+26];
		a[2] = array[rand()%10+52];
		a[3] = array[rand()%10+52];
		a[4] = '\0';

		printf("验证码:");
		printf("%s\n",a);
		printf("请输入验证码（Esc强制退回）：");
		scanf("%5s",b);
		while('\n'!=getchar());

		if(strcmp(a,b) != 0)
		{
			
			if(b[0]==27)
			{
				return -1;
			}
			printf("验证码错误，请重新输入！\n");
		}
		else
		{
			return 0;
		}
	}
}
/* ************************************************
@parameter:	char* str 输入字符数组传入地址
@return:	-1 包含空格,0 不包含
@explain:	检测输入内容是否包含空格等非法字符
 */
int string_check_blank(char* str){
	
	char*tmp = str;
	for(;(*tmp)!=0;tmp++){
		if((*tmp)==32||(*tmp)==27){
			printf("输入包含空格或其他非法字符\n");
			return -1;
		}
	}
	return 0;
 }
 /* ************************************************
@parameter:	short*num 输入数字保存至此地址对应变量
			int width 数字宽度,如2位数5位数等
@return:	0 成功,-1失败
@explain:	按宽度输入数字
 */
int num_input(int*num,int width){
	char input_tmp[64];
	
	for(int i=0;i<debugnum;i++){
		
		getstring(input_tmp,width+1);
		if(string_check_blank(input_tmp)<0||atoi(input_tmp)==0){
			printf("包含非法字符,请重新输入\n");
			continue;
		}
		*num = atoi(input_tmp);
		// printf("159n");
		return 0;
	}
	return -1;	
}
 /* ************************************************
@parameter:	uticket_t*uthead 用户彩票双向循环链表头结点
@return:	NONE
@explain:	保存用户彩票信息
 */
void save_uticket(uticket_t*uthead){
	 FILE* fp = fopen("./doc/user_ticket.txt","w");
	 if(fp==NULL){
		 printf("打开user_ticket.txt失败,返回\n");
		 return;
	 }
	 uticket_t*p = uthead->next;
	 
	 while(p!=uthead){
		 fwrite(p,1,sizeof(uticket_t),fp);
		 p = p->next;
	 }
	 fclose(fp);
 }
  /* ************************************************
@parameter:	uticket_t*uthead 用户彩票双向循环链表头结点
			unsigned int* ut_len 链表当前长度
@return:	NONE
@explain:	加载用户彩票彩票信息
 */
void load_uticket(uticket_t*uthead,unsigned int* ut_len){
	 FILE* fp = fopen("./doc/user_ticket.txt","r");
	 if(fp==NULL){
		 printf("打开user_ticket.txt失败,返回\n");
		 return;
	 }
	 uticket_t*p = uthead;
	 
	 int res ;
	 while(1){
		uticket_t* data = malloc(sizeof(uticket_t));
		memset(data,0,sizeof(uticket_t));
		res = fread(data,1,sizeof(uticket_t),fp);
		if(res==0){
			free(data);
			break;
		}
		data->prev = p;
		data->next = p->next;
		p->next = data;
		p = p->next;
		(*ut_len)++;
	 }
	 fclose(fp);
}
/* ********************************************************
@parameter: uticket_t*uhead链表头结点
@return:	NONE
@explain:	释放已经用户彩票空间							
*/
void free_uticket(uticket_t*uthead){
	uticket_t*p = uthead;
	while(p->next!=uthead){
		
		p = p->next;
		free(p->prev);		
	}
	free(p);
}
/* ********************************************************
@parameter: uticket_t*uthead链表头结点
@return:	NONE
@explain:	释放已经用户彩票空间							
*/
void remove_uticket(uticket_t*uthead,unsigned int* uticket_len,char*name){
	uticket_t*ut = uthead->next;
	uticket_t*ut_tmp;
	while(ut!=uthead){
		if(strcmp(name,ut->name)==0){
			ut_tmp = ut;
			ut->prev->next = ut->next;
			ut->next->prev = ut->prev;
			ut = ut->next;
			free(ut_tmp);
			(*uticket_len)--;
			printf("删除用户购买彩票记录成功\n");
		}else ut = ut->next;
		
	}
}

/* ************************************************
@parameter:	short(*bet_num)[4] 用户彩票五注号码二维数组指针23-21-42-45
@return:	NONE
@explain:	用户输入彩票号码
 */
void ticket_num_input(short *bet_num){
	short num[4];
	char input[4];
	int i;

	printf("请依次输入4组两位数,按回车确认\n");
	
	for(i=0;i<4;){
		printf("输入两位数,按回车确认\n");
		memset(input,0,sizeof(char));
		getstring(input,2+1);
		while(getchar()!=10);
		if(string_check_blank(input)<0){
			printf("包含非法字符,请重新输入\n");
			continue;
		}
		num[i] = atoi(input);
		if(num[i]==0){
			printf("非法输入,请输入数字\n");
			continue;
		}
		printf("本次输入的号码为%hd\n",num[i]);
		i++;
	}

	printf("您输入的4组号码为%hd-%hd-%hd-%hd\n",num[0],num[1],num[2],num[3]);
	memcpy(bet_num,num,sizeof(num));
	printf("本注彩票号码选择成功\n");

}
/* ******************************************************
@parameter:	uticket_t* uthead 发布彩票双向循环链表头结点
			char* name 用户姓名
@return:	找到的彩票指针,没有则空			
@explain:	管理员查找用户，若没有返回空						
*/
uticket_t* find_uticket(uticket_t* uthead,char* name){
	uticket_t*p = uthead->next;
	while(p!=uthead){
		if(strcmp(name,p->name)==0)return p;
		p = p->next;
	}
	return NULL	;
}
/* ******************************************************
@parameter:	uticket_t* uthead 发布彩票双向循环链表头结点
			char* name 用户姓名
@return:	找到的彩票指针,没有则空			
@explain:	查找中奖彩票						
*/
void search_win_uticket(uticket_t* uthead,char* name){
	uticket_t*p = uthead->next;
	short tmp_state;
	int i;
	printf("\t期号\tID\t\t中奖号码*****\n");
	while(p!=uthead){
		if(p->user_state>0&&strcmp(name,p->name)==0){
			tmp_state = p->user_state;
			for(i=4;i>=0;i--){
				if(tmp_state&0x01){
					printf("\t第%d期,%d号彩票中奖,中奖号码为%hd-%hd-%hd-%hd\n",p->issue,p->id,
							p->bet_num[i][0],p->bet_num[i][1],p->bet_num[i][2],p->bet_num[i][3]);
				}					
				tmp_state = tmp_state>>1;
			}		
		}		
		p = p->next;
	}
}
/* ************************************************
@parameter:	uticket_t* uthead 发布彩票双向循环链表头结点
			char* name 用户姓名
@return:	NONE
@explain:	查找浏览用户购买彩票记录
 */
void looking_for_uticket(uticket_t* uthead,char* name){
	uticket_t*ut 	= uthead->next;
	int i;
	printf("************用户购买彩票记录******************\n");
	printf("\t期号\tID\t购买者\t开奖状态\t中奖金额\n");

	while(ut!=uthead){
		if(strcmp(name,ut->name)==0){
			printf("\t%d\t%d\t%s\t%s\t\t%d\n",ut->issue,ut->id,ut->name,(ut->user_state!=0)?"已开奖":"未开奖",ut->win_bonus);
			for(i=0;i<ut->bet_cnt;i++){
				printf("\t\t购买号码:%hd-%hd-%hd-%hd\n",ut->bet_num[i][0],ut->bet_num[i][1],ut->bet_num[i][2],ut->bet_num[i][3]);
			}
			
		}
		ut = ut->next;
	}
}
/* ************************************************
@parameter:	uticket_t* uthead 彩票链表头结点
			unsigned int* uticket_len 链表当前长度
@return:	
@explain:	查询用户彩票
 */
void uticket_print(uticket_t* uthead){
	uticket_t*ut = uthead->next;
	int i;
	printf("****中奖彩票信息****\n");
	printf("****彩票ID\t期号\t用户ID\t购买注数\t中奖状态\t中奖金额****\n");
	printf("****购买号码****\n");
	while(ut!=uthead){
		if(ut->user_state>0){
			printf("\t%d\t%d\t%s\t%d\t%d\t%d\n",ut->id,ut->issue,ut->name,ut->bet_cnt,ut->user_state,ut->win_bonus);
			for(i=0;i<5;i++){
				printf("\t\t\t%hd-%hd-%hd-%hd\n",ut->bet_num[i][0],ut->bet_num[i][1],ut->bet_num[i][2],ut->bet_num[i][3]);
			}
		}
		ut = ut->next;
	}
}
/* ************************************************
@parameter:	uticket_t* uticket_head 彩票链表头结点
			unsigned int* uticket_len 链表当前长度
@return:	
@explain:	用户购买彩票
 */
void uticket_buying(uticket_t* ut_head,unsigned int* uticket_len,user_t*uhead,aticket_t*ahead,char* name){
	uticket_t*ut = ut_head->next;
	aticket_t*at  = ahead;
	user_t*tar;
	int ch,i,j;

	uticket_t data = {0};
	
	while(ut->next!= ut_head){//用户彩票到末尾
		ut = ut->next;
	}
	while(at->next!= ahead){//发行彩票到末尾
		at = at->next;
	}
	if(at->issue<1||at->open_state!=false){
		printf("新一期彩票未发行,请耐心等待\n");
		return;
	}
	tar = find_user(uhead,name);
	if(tar==NULL){
		printf("未找到该用户名,程序出错,返回\n");
		return;
	}

	printf("本期彩票每注%d元,每张彩票最多购买五注,请输入号码\n",at->price);	
	for( j=0;j<5;){
		int res = tar->balance - at->price;
		if(res < 0){
			printf("余额不足,本次无法购买,开始充值!!!\n");
			if((deposit(uhead,name)- at->price)<0)return;
			printf("充值成功,继续购买彩票\n");
			
		}
		
		ticket_num_input(data.bet_num[j]);		
		tar->balance -= at->price;
		j++;			
		if(j<4){
			printf("停止选号请按0,其它则继续选号\n");
			scanf("%d",&ch);
			while(getchar()!=10);
			if(ch==0)break;
		}						
	}	
	
	printf("\t\t本次共购买%d注号码,\n",j);
	for(i=0;i<j;i++){
		printf("\t\t%hd-%hd-%hd-%hd\n",data.bet_num[i][0],data.bet_num[i][1],data.bet_num[i][2],data.bet_num[i][3]);
	}
	
	uticket_t* new_ut = calloc(1,sizeof(uticket_t));
	
	new_ut->issue 		= at->issue;					//期号 源于开奖期号
	new_ut->id			= ut->id+1;						//彩票唯一ID
	memcpy(new_ut->bet_num,data.bet_num,sizeof(data.bet_num));	//购买号码，每张彩票最多五注
	new_ut->bet_cnt		= j;
	// printf("ut->id=%d\n",ut->id);
	// printf("new_ut->bet_cnt=%d\n",new_ut->bet_cnt);
	// for(i=0;i<new_ut->bet_cnt;i++){
		// printf("\t\t%hd-%hd-%hd-%hd\n",new_ut->bet_num[i][0],new_ut->bet_num[i][1],new_ut->bet_num[i][2],new_ut->bet_num[i][3]);
	// }
	strcpy(new_ut->name,name);							//购买者id
	new_ut->user_state	= UNKNOW;						//中奖状态		
	new_ut->win_bonus	= 0;							//中奖金额
	
	new_ut->prev		= ut;
	new_ut->next 		= ut->next;
	ut->next 			= new_ut;
	(*uticket_len)++;
	printf("彩票购买成功\n");
	printf("\n\n");
} 
void lottery_initial(aticket_t*ahead, uticket_t* ut_head,user_t*uhead){
	
	ahead->next = ahead;
	ahead->prev = ahead;
	unsigned int aticket_len = 0;	
	
	uhead->next = NULL;
	unsigned int user_len = 0;
	
	ut_head->next = ut_head;
	ut_head->prev = ut_head;
	unsigned int uticket_len = 0;
	
#if ADMIN_ADDED	//
	admin_worker_added(uhead,&user_len);
	save_user(uhead);
	free_user(uhead);
#endif
	load_uticket(ut_head,&uticket_len);
	load_aticket(ahead,&aticket_len);
	load_user(uhead,&user_len);

	int res;
	char ch;
	char returnname[20];
	
	while(1){
		printf("--------欢迎进入福利彩票中心---------\n");
		printf("----小买怡情，大买伤身，强买灰飞烟灭----\n");
		printf("1:\t注册\n");
		printf("2:\t登录\n");
		printf("0:\t退出\n");
		printf("其它输入无效\n");
		scanf("%c",&ch);
		while(getchar()!=10);
		switch(ch){
			case '1':
				regist_user(uhead,&user_len);
			break;
			case '2':
				res = login_user(uhead,user_len,returnname);
				if(res==2){
					worker_action(ahead,&aticket_len,ut_head,uhead);
				}else if(res==1){
					admin_action(ahead,&aticket_len,ut_head,uhead);
				}else if(res == 0){
					user_action(ut_head,&uticket_len,uhead,&user_len,ahead,returnname);
				}else{}
				
			break;
			case '0':
				save_uticket(ut_head);
				save_aticket(ahead);
				save_user(uhead);
				free_uticket(ut_head);
				free_aticket(ahead);
				free_user(uhead);
				return;
			break;
			default:
				printf("无效输入，请重新输入\n");
			break;
		}
	}	
}





