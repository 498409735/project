
#include "user.h"
#include "lottery.h"
/* ******************************************************
@parameter: user_t*head 用户单向不循环链表头结点
			unsigned int* user_len 链表当前长度
@return:	NONE
@explain:	添加管理员和公证员						
*/
void admin_worker_added(user_t*head,unsigned int* user_len){
	user_t* p = head;
	while(p->next!= NULL){
		p = p->next;
	}
	user_t* new_user = malloc(sizeof(user_t));
	memset(new_user,0,sizeof(user_t));
	strcpy(new_user->name,admin);
	strcpy(new_user->pswd,adminpswd);
	p->next = new_user;
	(*user_len)++;
	p = p->next;
	new_user = malloc(sizeof(user_t));
	memset(new_user,0,sizeof(user_t));
	strcpy(new_user->name,worker);
	strcpy(new_user->pswd,workerpswd);
	p->next = new_user;
	(*user_len)++;
	p = p->next;
	
}
/* ******************************************************
@parameter: user_t*head 用户单向不循环链表头结点
@return:	找到的用户指针
@explain:	管理员查找用户，若没有返回空						
*/
user_t* find_user(user_t*head,char* tmp){
	user_t*p = head->next;
	while(p!=NULL){
		if(strcmp(tmp,p->name)==0)return p;
		p = p->next;
	}
	return NULL	;
}
/* ********************************************************
@parameter: user_t*head 用户单向不循环链表头结点
@return:	NONE
@explain:	释放已经用户空间						
*/
void free_user(user_t*head){
	user_t*p = head;
	user_t*tmp = 0;
	while(p!=NULL){
		tmp = p->next;	
		free(p);
		p = tmp;	
						
	}
}
/* ************************************************
@parameter:	user_t*head 用户单向不循环链表头结点
			unsigned int* user_len 链表当前长度
@return:	NONE
@explain:	添加新用户
 */
int remove_user(uticket_t*uthead,unsigned int* uticket_len,user_t*head,unsigned int* user_len,char* name){
	user_t* u = head;
	
	remove_uticket(uthead,uticket_len,name);
	
	user_t* tar = find_user(head,name);
	if(tar!=NULL){
		while(u->next!=tar){
			u = u->next;
		}
		u->next = tar->next;
		free(tar);
		(*user_len)--;
		printf("注销成功\n");
		return 0;
	}else {
		printf("未找到该用户，程序出错\n");
		return -1;
	}

}
/* ************************************************
@parameter:	user_t*head 用户单向不循环链表头结点
			unsigned int* user_len 链表当前长度
@return:	NONE
@explain:	注册添加新用户
 */
void regist_user(user_t*head,unsigned int* user_len){
	user_t*p = head;
	
	char name[100];
	char pswd1[20];
	char pswd2[20];
	int i,j,len;
	for( j=0;j<debugnum;j++){
		printf("请输入注册id,不能包含空格或其他非法字符,长度在1-20之间\n");
		for( i=0;i<debugnum;i++){
			len = getstring(name,30);
			if(string_check_blank(name)<0)return;
			if(len>0&&len<20){
				break;
			}else return;
			printf("长度大于20，请重新输入\n");
		}
		if(i>=debugnum){
			printf("输入长度超过20，多次调戏电脑，返回\n");
			return;
		}		
		user_t* res = find_user(head,name);
		if(strcmp(name,admin)!=0&&strcmp(name,worker)!=0&&res==NULL){
			break;
		}
		printf("此用户名已被注册，请重新输入\n");
	}
	if(j>=debugnum){
		printf("输入次数过多，返回\n");
		return;
	}
	
	for(j=0;j<debugnum;j++){
		printf("请输入注册密码,不能包含空格或其他非法字符,长度在1-20之间\n");
		if(getPassword(pswd1)<0){
			printf("非法输入,返回\n");
			return;
		}
		if(string_check_blank(pswd1)<0){
			printf("请重新输入");
			continue;
		}
		printf("请再次输入密码\n");
		if(getPassword(pswd2)<0){
			printf("非法输入,返回\n");
			return;
		}
		if(string_check_blank(pswd2)<0){
			printf("请重新输入");
			continue;
		}
		if(strcmp(pswd1,pswd2)==0){
			while(p->next!= NULL){
				p = p->next;
			}
			user_t* new_user = malloc(sizeof(user_t));
			memset(new_user,0,sizeof(user_t));
			strcpy(new_user->name,name);
			strcpy(new_user->pswd,pswd2);
			p->next = new_user;
			(*user_len)++;
			printf("注册成功\n");
			return;
		}
		printf("密码输入不一致，请重新输入\n");
	}
	if(j>=debugnum){
		printf("密码输入次数过多，返回\n");
		return;
	}	
}
/* ************************************************
@parameter:	user_t*head 用户单向不循环链表头结点
@return:	NONE
@explain:	保存用户信息
 */
void save_user(user_t*head){
	 FILE* fp = fopen("./doc/USER.txt","w");
	 if(fp==NULL){
		 printf("打开../doc/USER.txt失败,返回\n");
		 return;
	 }
	 user_t*p = head->next;
	 
	 while(p!=NULL){
		 fwrite(p,1,sizeof(user_t),fp);
		 p = p->next;
	 }
	 fclose(fp);
 }
 /* ************************************************
@parameter:	user_t*head 用户单向不循环链表头结点
			unsigned int user_len 链表当前长度
@return:	NONE
@explain:	加载用户信息
 */
void load_user(user_t*head,unsigned int* user_len){
	 FILE* fp = fopen("./doc/USER.txt","r");
	 if(fp==NULL){
		 printf("打开../doc/USER.txt失败,返回\n");
		 return;
	 }
	 
	 user_t*p = head;
	 user_t data ={0};
	 int res ;
	 while(1){		
		res = fread(&data,1,sizeof(user_t),fp);
		if(res==0){break;}
		user_t* new_user = malloc(sizeof(user_t));
		memset(new_user,0,sizeof(user_t));
		memcpy(new_user,&data,sizeof(user_t));		
		p->next = new_user;
		p = p->next;
		(*user_len)++;
	 }
	 fclose(fp);
}
/* ************************************************
@parameter:	user_t*head 用户单向不循环链表头结点
			unsigned int user_len 链表当前长度
@return:	NONE
@explain:	打印用户信息
 */
void print_all_user(user_t*head){

	 user_t*p = head->next;

	 printf("************用户信息******************\n");
	  printf("\t用户名\t\t余额\n");
	 while(p!=NULL){
		 if(strcmp(p->name,admin)!=0&&strcmp(p->name,worker)!=0){
			printf("\t%s\t\t%d\n",p->name,p->balance);
		 }		 
		 p = p->next;
	 }
	printf("\n\n");
}

/* ************************************************
@parameter:	user_t*head 用户单向不循环链表头结点
			unsigned int user_len 链表当前长度
@return:	0 成功登录，1 登录失败
@explain:	登录用户，即链表查找
 */
int login_user(user_t*head,unsigned int user_len,char*returnname){
	user_t* tar;
	char name[20];
	char pswd[20];
	int i,len;
	
	for( i =0;i<debugnum;i++){
		printf("请输入用户名\n");
		len = getstring(name,20);		
		if(len<=0){
			printf("无效输入,返回\n");
			return -1;
		}
		
		tar = find_user(head,name);
		if(tar!=NULL){
			break;
		}
		printf("用户名不存在，请重新输入\n");
	}
	if(i>=debugnum){
		printf("输入次数过多，返回\n");
		return -1;
	}
	
	for(i =0;i<debugnum;i++){
		// if(identifyCode()<0){
			// printf("操作取消，返回\n");
			// return -1; 
		// }
		printf("请输入密码\n");
		getPassword(pswd);
		
		if(strcmp(tar->pswd,pswd)==0){
			if(strcmp(name,admin)==0){
				printf("管理员登录成功\n");
				return 1;
			}
			if(strcmp(name,worker)==0){
				printf("公证员登录成功\n");
				return 2;
			}
			printf("登录成功\n");
			strcpy(returnname,name);
			return 0;
		}
		printf("密码输入错误，请重新输入\n");
	}
		printf("密码输入次数过多，返回\n");
		return -1;
}
 /* ************************************************
@parameter:	user_t*head 用户单向不循环链表头结点
			char* name 已经登录的用户名
@return:	NONE
@explain:	修改密码
 */
void pswd_modify(user_t*head,char* name){
	char pswd[20];
	char newpswd1[20];
	char newpswd2[20];
	int i;
	user_t* tar = find_user(head,name);
	if(tar==NULL){
		printf("程序出错\n");
		return;
	}
	
	if(identifyCode()<0){
		printf("操作取消，返回\n");
		return;
	} 
	for( i=0;i<debugnum;i++ ){
		printf("请输入旧密码\n");
		getPassword(pswd);
		if(strcmp(tar->pswd,pswd)==0)break;
		printf("密码输入错误，请重新输入\n");
	}
	if(i>=debugnum){
		printf("输入次数过多，返回\n");
		return;
	}
	for(i=0;i<debugnum;i++){
		printf("请输入新密码\n");
		getPassword(newpswd1);
		printf("请再次输入密码\n");
		getPassword(newpswd2);
		if(strcmp(newpswd1,newpswd2)==0){
			strcpy(tar->pswd,newpswd1);
			printf("密码修改成功，返回\n");
			return;
		}
		printf("两次输入不一致,请重新输入\n");
	}
	printf("输入次数过多，疑似调戏计算机，返回\n");
}	
/* ************************************************
@parameter:	user_t*head 用户单向不循环链表头结点
			char* name 已经登录的用户名
@return:	-1 失败,int 充值金额
@explain:	充值
 */
int deposit(user_t*head,char* name){
	int deposit_money,ch;
	user_t* tar = find_user(head,name);
	if(tar==NULL){
		printf("程序出错\n");
		return -1;
	}
	// if(identifyCode()<0){
		// printf("操作取消，返回\n");
		// return -1;
	// } 
	for(int i=0;i<debugnum;i++){
		printf("请输入充值金额\n");
		if(num_input(&deposit_money,10)<0)return -1;
		// scanf("%d",&deposit_money);
		// while(getchar()!=10);

		deposit_money= (deposit_money>1)?deposit_money:1;
		printf("您充值金额为%d,确认请按1,重新输入请按2,返回请按0\n",deposit_money);
		scanf("%d",&ch);
		while(getchar()!=10);
		switch(ch){
			case 1:
				tar->balance = tar->balance+deposit_money;
				printf("充值成功!,余额%d\n",tar->balance);
				return tar->balance;
			break;
			case 2:
				continue;
			break;
			case 0:
				return -1;
			break;
			default:
				printf("无效输入，请重新操作\n");
			break;
		}
	}
	printf("无效输入次数过多,返回\n");
	return -1;
}

/* ************************************************
@parameter:	user_t*head 用户单向不循环链表头结点
			unsigned int user_len 链表当前长度
@return:	
@explain:	用户操作
 */
void user_action(uticket_t* ut_head,unsigned int* uticket_len,user_t*uhead,unsigned int* user_len,aticket_t*ahead,char* name){
	 int ch;
	 while(1){
		 printf("*********个人登录界面*******\n");
		printf("1:\t查看个人信息\n");
		printf("2:\t修改密码\n");
		printf("3:\t注销个人信息,删除所有购票记录\n");
		printf("4:\t充值\n");
		printf("5:\t查询中奖记录\n");
		printf("6:\t购买彩票\n");
		printf("7:\t查询购票记录\n");
		printf("8:\t猜拳游戏\n");
		printf("0:\t返回\n");
		scanf("%d",&ch);
		while(getchar()!=10);
		switch(ch){
			case 1:
				print_user(uhead,name);
			break;
			case 2:
				pswd_modify(uhead,name);
			break;
			case 3:
				if(remove_user(ut_head,uticket_len,uhead,user_len,name)==0)return;
			break;
			case 4:
				deposit(uhead,name);
			break;
			case 5:
				search_win_uticket(ut_head,name);
			break;
			case 6:
				uticket_buying(ut_head,uticket_len,uhead,ahead,name);
			break;
			case 7:
				looking_for_uticket(ut_head,name);
			break;
			case 8:
				user_game(uhead,name);
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
@parameter:	user_t*head 用户单向不循环链表头结点
			char* name 已经登录的用户名
@return:	NONE
@explain:	打印个人用户信息
 */
void print_user(user_t*head,char* name){
	user_t* tar;
	
	tar = find_user(head,name);
	if(tar==NULL){
		printf("程序出错\n");
		return;
	}	
	
	// if(identifyCode()<0){
		// printf("操作取消，返回\n");
		// return; 
	// }
	printf("************用户信息******************\n");
	printf("\t用户名\t余额\n");
	printf("\t%s\t%d\n",tar->name,tar->balance);

}
/* ************************************************
@parameter:	user_t*head 用户单向不循环链表头结点
			char* name 已经登录的用户名
@return:	NONE
@explain:	赢取金额小游戏
*/
void user_game(user_t*head,char* name){
	user_t* tar;
	int sys_num, uer_num;
	int i;
	tar = find_user(head,name);
	if(tar==NULL){
		printf("程序出错\n");
		return;
	}
	printf("猜拳赢余额小游戏,系统出一个数字,如果用户三次猜中,则余额加1元\n");
	srand(time(NULL));
	sys_num = rand()%98+1;
	printf("\n");
	printf("系统已出该数字,请用户输入猜的数字\n");
	printf("%d\n",sys_num);
	for(i=0;i<3;i++){
		scanf("%d",&uer_num);
		while(getchar()!=10);
		if(uer_num==sys_num){
			tar->balance+=1;
			printf("恭喜您,猜中数字,已将1元添加至余额\n");
			return;
		}else if(uer_num>sys_num){
			printf("大了,请重新输入\n");
		}else{
			printf("小了,请重新输入\n");
		}
	}
	printf("没有猜中,返回\n");
}
 
 
 
 
 