#ifndef LOTTERY_H
#define LOTTERY_H



#include "head.h"
// #include "user.h"
// #include "admin.h"

int getch();
int getPassword(char *pcPWD);
int getstring(char* str,unsigned int len);
int identifyCode(void);
int string_check_blank(char* str);
int num_input(int*num,int width);
void save_uticket(uticket_t*uthead);
void load_uticket(uticket_t*uthead,unsigned int* ut_len);
void free_uticket(uticket_t*uhead);
void remove_uticket(uticket_t*uthead,unsigned int* uticket_len,char*name);
void ticket_num_input(short *bet_num);
uticket_t* find_uticket(uticket_t* uthead,char* name);
void search_win_uticket(uticket_t* uthead,char* name);
void looking_for_uticket(uticket_t* uthead,char* name);
void uticket_print(uticket_t* uthead);
void uticket_buying(uticket_t* ut_head,unsigned int* uticket_len,user_t*uhead,aticket_t*ahead,char* name);
void lottery_initial(aticket_t*ahead, uticket_t* ut_head,user_t*uhead);

#endif