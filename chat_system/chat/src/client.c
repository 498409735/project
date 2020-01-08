#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <unistd.h>
#include <netdb.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <string.h>
#include <pthread.h>


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
void*task(void*arg){
	int ret;
	int readfd = *(int*)arg;
	char buf[512] = "";
	while(1){
		ret = read(readfd,buf,512);
		printf("len:%d\nRe:%s\n",ret,buf);
		memset(buf,0,512);
	}
	return NULL;
}
void top_view(int fd){
	puts("*********欢迎来到xxx聊天室*********");
	puts("**************1:注册*********");
	puts("**************2:登录*********");
	puts("**************0:退出*********");
	scanf("%d",&choice);
	switch(choice)
	{
	 case 1://注册
		{//语句块
		  protocol pack;//定义协议包变量
		  memset((void*)&pack,0,sizeof(protocol));//清空结果体
		  printf("请输入用户名:");
		  scanf("%s",pack.name);
		  while(getchar()!=10);//吸收换行符
		  printf("请输入密码:");
		  scanf("%s",pack.passwd);
		  while(getchar()!=10);//吸收换行符
		  printf("你输入的用户名是:%s,密码是:%s\n",pack.name,pack.passwd);
		  pack.type = TYPE_REG;//设置包类型
		  //发送注册包到服务器
		  retval = write(fd,(void*)&pack,sizeof(protocol));
		  printf("发送了%d字节到服务器:username=%s,passwd=%s,type=%d\n",retval,pack.name,pack.passwd,pack.type);
		  memset((void*)&pack,0,sizeof(protocol));//清空结果体
		  retval = read(fd,(void*)&pack,sizeof(protocol));
		  printf("从服务器读到%d字节:type=%d\n",retval,pack.type);
		  if(pack.type==TYPE_OK)
		  {
			 puts("注册成功...");
		  }else{
			 puts("注册失败...");
		  }
		}
		break;
	 case 2://登录
		break;
	 case 0://退出
		break;
	 default://错误情况
		printf("请输入正确的选项编号\n");
		break;
	}
}
int main(int argc,char*argv[]){
	int fd = socket(AF_INET,SOCK_STREAM,0);
	if(fd<0){
		perror("socket initial failed...");
		close(fd);
		exit(1);
	}
	int ret;
	
	struct sockaddr_in server;
	server.sin_family 		= AF_INET;
	server.sin_port 		= htons(8990);
	server.sin_addr.s_addr 	= inet_addr("192.168.16.128");
	if(connect(fd,(struct sockaddr*)&server,sizeof(struct sockaddr_in))<0){
		perror("connetct to server failen..");
		close(fd);
		exit(1);
	}
	pthread_t thread;
	pthread_attr_t attr;
	pthread_attr_init(&attr);
	pthread_attr_setdetachstate(&attr,PTHREAD_CREATE_DETACHED);
	pthread_create(&thread,&attr,task,(void*)&fd);
	
	
	while(1){
		top_view(fd);
	}
	pthread_cancel(thread);
	pthread_attr_destroy(&attr);
	close(fd);
	return 0;
}