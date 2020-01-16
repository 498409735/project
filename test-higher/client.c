#include <stdio.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <unistd.h>
#include <sys/un.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <pthread.h>

/*     int socket(int domain, int type, int protocol);
domain:
	AF_UNIX, AF_LOCAL   Local communication              unix(7)
	AF_INET             IPv4 Internet protocols          ip(7)
	AF_INET6            IPv6 Internet protocols          ipv6(7)
	AF_IPX              IPX - Novell protocols
	AF_NETLINK          Kernel user interface device     netlink(7)
	AF_X25              ITU-T X.25 / ISO-8208 protocol   x25(7)
	AF_AX25             Amateur radio AX.25 protocol
	AF_ATMPVC           Access to raw ATM PVCs
	AF_APPLETALK        AppleTalk                        ddp(7)
	AF_PACKET           Low level packet interface       packet(7)
	AF_ALG              Interface to kernel crypto API
type:
	SOCK_STREAM     
	SOCK_DGRAM      
	SOCK_SEQPACKET  
	SOCK_RAW        
	SOCK_RDM        
	SOCK_PACKET  
 */
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
	int readfd =*(int*)arg;
	// dup2(clientfd,1);
	printf("%s,readfd=%d\n",__FUNCTION__,readfd);
	char buf[512]="";
	while(1){
		ret = read(readfd,buf,512);
		printf("从服务端读到%d字节:%s\n",ret,buf);
		memset(buf,0,512);
	}
	// close(readfd);
	return NULL;
}
int main(int argc,char*argv[]){
	int fd;
	fd = socket(AF_INET,SOCK_STREAM,0);
	printf("fd = %d\n",fd);
	
	struct sockaddr_in server;
	server.sin_family = AF_INET;
	server.sin_port = htons(8990);
	server.sin_addr.s_addr = inet_addr("192.168.8.130");
	int ret;
	ret  = connect(fd,(struct sockaddr*)&server,(socklen_t)sizeof(struct sockaddr_in));
	printf("connect ret = %d\n",ret);
	if(ret<0){
		perror("bind failed...");
		goto out;
	}
	pthread_t thread;
	pthread_attr_t attr;
	pthread_attr_init(&attr);
	// pthread_attr_setdetachstate(&attr,PTHREAD_CREATE_DETACHED);
	pthread_create(&thread,&attr,task,(void*)&fd);
	
	char buf[100]="";
	ret = read(fd,buf,100);
	printf("Recieve:%s,len =%d\n",buf,ret);
	memset(buf,0,100);
	while(1){
		printf("请输入发送信息\n");
		getstring(buf,100);
		ret = write(fd,buf,strlen(buf));
		if(strcmp(buf,"end")==0)break;
		printf("Send:%d Byte to server\n",ret);
		memset(buf,0,100);
	}
	
out:
	pthread_cancel(thread);
	pthread_attr_destroy(&attr);
	printf("end...");
	close(fd);
	return 0;
}