#ifndef HEAD_H
#define HEAD_H

typedef unsigned char     uint8_t;  
typedef unsigned short    uint16_t;
typedef unsigned long     uint32_t;
 
typedef uint32_t  u32; 
typedef uint16_t u16;
typedef uint8_t  u8;
/* **************用户及在线用户链表**************** */
typedef struct User{
	char name[20];
	char pswd[20];
}user_t;
typedef struct User_link{
	user_t user;
	struct User_link* prev;
	struct User_link* next;
}
typedef struct Online_user{
	user_t user;
	struct Online_user* prev;
	struct Online_user* next;
}
/* ***********协议包***************** */
typedef struct Data{
	u8 type;
	char name[20];
	char pswd[20];
	char chat_name_rec[20];
	char chat_name_send[20];
	char chat_data[512];
}data_t;
/* ****************关键定义**************** */
#define WR				0
#define RD				1
/* ****************消息类型*************** */
#define TYPE_LOGIN		1	//			登录
#define TYPE _REG		2	//			注册数据包
#define TYPE _MSG		3	//			消息数据包
#define TYPE _HEART		4	//			心跳数据包
#define	TYPE _CMD		5	//			命令数据包
#define TYPE_ONLINE		6	//			查看在线用户
#define TYPE_OK			7	//			服务器返回OK包
#define TYPE_ERROR		8	//			服务器返回错误包 

#endif