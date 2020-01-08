#ifndef USER_H
#define USER_H

#include "head.h"

void admin_worker_added(user_t*head,unsigned int* user_len);
user_t* find_user(user_t*head,char* tmp);
void free_user(user_t*head);
int  remove_user(uticket_t*uthead,unsigned int* uticket_len,user_t*head,unsigned int* user_len,char* name);
void regist_user(user_t*head,unsigned int* user_len);
void save_user(user_t*head);
void load_user(user_t*head,unsigned int* user_len);
void print_all_user(user_t*head);
int  login_user(user_t*head,unsigned int user_len,char*returnname);
void pswd_modify(user_t*head,char* name);
int	 deposit(user_t*head,char* name);
void user_action(uticket_t* ut_head,unsigned int* uticket_len,user_t*uhead,unsigned int* user_len,aticket_t*ahead,char* name);
void print_user(user_t*head,char* name);
void user_game(user_t*head,char* name);

#endif

/* user_t* user_head = malloc(sizeof(user_t));
	memset(user_head,0,sizeof(user_t));

	user_head->next = NULL;
	unsigned int user_len = 0;
	load_user(user_head,&user_len);
	print_all_user(user_head);
	remove_user(user_head,&user_len,"as");
	// insert_user(user_head,&user_len);
	// insert_user(user_head,&user_len);
	// insert_user(user_head,&user_len);
	// insert_user(user_head,&user_len);

	save_user(user_head,user_len);
	free_user(user_head); */