
#include "lottery.h"

int main(){
	aticket_t* aticket_head = calloc(1,sizeof(aticket_t));	//发行彩票链表创建
	uticket_t* uticket_head = calloc(1,sizeof(uticket_t));	//个人彩票链表创建
	user_t* user_head = calloc(1,sizeof(user_t));			//用户信息链表创建
	
	lottery_initial(aticket_head,uticket_head,user_head);
	return 0;
}

















