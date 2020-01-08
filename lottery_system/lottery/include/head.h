#ifndef HEAD_H
#define HEAD_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <unistd.h>  
# include<termios.h>  
# include<assert.h> 
#include <time.h>

#define ADMIN_ADDED	0	//添加管理员，开启一次即可
#define debugnum 	3	//调试方便错误检测次数，正常为10

extern char admin[];
extern char adminpswd[];
extern char worker[];
extern char workerpswd[];		

#define FIFTH_WIN			0x01
#define FOUTH_WIN			0x02
#define THIRDE_WIN			0x04
#define SECOND_WIN			0x08
#define FIRST_WIN			0x10
#define UNKNOW				0
#define NOT_WIN				-1

typedef struct User{//单向不循环链表，其实一点也不好用
	char name[20];	//用户名
	char pswd[20];	//密码
	unsigned int  balance;	//余额
	struct User* next;
}user_t;
typedef struct User_ticket{		//双向循环链表
	unsigned int issue;			//期号 源于开奖期号
	unsigned int id;			//彩票唯一ID
	short bet_num[5][4];		//购买号码，每张彩票最多五注
	unsigned short bet_cnt;		//购买注数
	char name[20];				//购买者id		
	short user_state;			//中奖状态		//11111 左移一位,高位-低位表示第几注中奖第一注,第二注,第三注,第四注,第五注中奖
	unsigned int win_bonus;		//中奖金额
	struct User_ticket*prev;
	struct User_ticket* next;
}uticket_t;
typedef struct Admin_ticket{	//双向循环链表
	unsigned int issue;			//期号
	unsigned int price;			//每注单价
	bool open_state;			//开奖状态
	short win_num[4];			//中奖号码23-45-23-34
	unsigned int selle_count;	//售出总数
	unsigned int jackpot;		//奖池金额
	struct Admin_ticket*prev;
	struct Admin_ticket* next;
}aticket_t;


#endif


