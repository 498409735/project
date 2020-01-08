#ifndef ADMIN_H
#define ADMIN_H

#include "head.h"

void free_aticket(aticket_t*head);
void remove_aticket(aticket_t*athead,unsigned int* aticket_len);
void publish_admin(aticket_t*head,unsigned int* aticket_len);
void print_all_aticket(aticket_t*head);
void save_aticket(aticket_t*head);
void load_aticket(aticket_t*head,unsigned int* aticket_len);
int auto_drawing(short* arr);
int manuel_drawing(short* arr);
int drawing_select(short* arr);
void lottery_drawing(aticket_t*head,uticket_t* uthead,user_t*uhead);
void browse_user(user_t*uhead);
void user_bubble(user_t*uhead);
void admin_action(aticket_t*ahead,unsigned int* aticket_len,uticket_t* uthead,user_t*uhead);
void worker_action(aticket_t*athead,unsigned int* aticket_len,uticket_t* uthead,user_t*uhead);

#endif

/* 	aticket_t* aticket_head = malloc(sizeof(aticket_t));
	memset(aticket_head,0,sizeof(aticket_t));

	aticket_head->next = aticket_head;
	aticket_head->prev = aticket_head;
	unsigned int aticket_len = 0;
	
	load_admin(aticket_head,&aticket_len);
	// publish_admin(aticket_head,&aticket_len);
	// publish_admin(aticket_head,&aticket_len);
	// publish_admin(aticket_head,&aticket_len);
	// publish_admin(aticket_head,&aticket_len);
	print_all_aticket(aticket_head);
	// save_admin(aticket_head, aticket_len);
	free_aticket(aticket_head); */