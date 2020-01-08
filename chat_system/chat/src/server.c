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

pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;
void*task(void*arg){
	int ret;
	int clientfd =*(int*)arg;
	int tmpfd;
		
	printf("%s,clientfd=%d\n",__FUNCTION__,clientfd);
	char buf[100]="";
	while(1){
		ret = read(clientfd,buf,100);
		if(ret==0){
			printf("%d客户端已断开\n",clientfd);
			break;
		}
		printf("从%d客户端读到%d字节:%s\n",clientfd,ret,buf);
		pthread_mutex_lock(&mutex);
		tmpfd = dup(1);
		dup2(clientfd,1);
		system(buf);
		dup2(tmpfd,1);
		pthread_mutex_unlock(&mutex);
		memset(buf,0,100);
		
	}
	
	close(clientfd);
	return NULL;
}
int main(int argc,char*argv[]){
	int fd;
	fd = socket(AF_INET,SOCK_STREAM,0);
	printf("fd = %d\n",fd);
	
	int on =1;
	if(setsockopt(fd,SOL_SOCKET,SO_REUSEADDR,&on,sizeof(int))<0)
		exit(-1);
	
	struct sockaddr_in server;
	server.sin_family = AF_INET;
	server.sin_port = htons(8990);
	server.sin_addr.s_addr = inet_addr("192.168.8.130");
	int ret;
	ret  = bind(fd,(struct sockaddr*)&server,(socklen_t)sizeof(struct sockaddr_in));
	printf("bind ret = %d\n",ret);
	if(ret<0){
		perror("bind failed...");
		goto out;
	}
	ret = listen(fd,10);
	printf("listen =ret =%d\n",ret);
	if(ret<0){
		perror("listen failen..");
	}
	
	int clientfd;
	struct sockaddr_in client;
	socklen_t len =0;
	pthread_t thread[100];
	int client_no =0;
	pthread_attr_t attr[100];
	while(1){
		printf("accept..\n");
		clientfd = accept(fd,(struct sockaddr*)&client,&len);
		printf("client fd =%d:IP=%s,PORT=%d\n",clientfd,inet_ntoa(client.sin_addr),ntohs(client.sin_port));

		char* str = "欢迎光临...";
		ret = write(clientfd,str,strlen(str));
		printf("发送%d字节到客户端...\n",ret);
		pthread_attr_init(&attr[client_no]);
		pthread_attr_setdetachstate(&attr[client_no],PTHREAD_CREATE_DETACHED);
		pthread_create(&thread[client_no],&attr[client_no],task,(void*)&clientfd);
		client_no++;
	}

out:
	pthread_mutex_destroy(&mutex);
	printf("end...");
	close(fd);
	return 0;
}
/* void*task(void*arg){
	int ret;
	int clientfd =*(int*)arg;
	printf("%s,clientfd=%d\n",__FUNCTION__,clientfd);
	char buf[100]="";
	while(1){
		ret = read(clientfd,buf,100);
		printf("从%d客户端读到%d字节:%s\n",clientfd,ret,buf);
		memset(buf,0,100);
		if(ret==0){
			printf("%d客户端已断开\n",clientfd);
			break;
		}
	}
	close(clientfd);
	return NULL;
} */
/* int main(int argc,char*argv[]){
	int fd;
	fd = socket(AF_INET,SOCK_STREAM,0);
	printf("fd = %d\n",fd);
	
	int on =1;
	if(setsockopt(fd,SOL_SOCKET,SO_REUSEADDR,&on,sizeof(int))<0)
		exit(-1);
	
	struct sockaddr_in server;
	server.sin_family = AF_INET;
	server.sin_port = htons(8990);
	server.sin_addr.s_addr = inet_addr("192.168.16.128");
	int ret;
	ret  = bind(fd,(struct sockaddr*)&server,(socklen_t)sizeof(struct sockaddr_in));
	printf("bind ret = %d\n",ret);
	if(ret<0){
		perror("bind failed...");
		goto out;
	}
	ret = listen(fd,10);
	printf("listen =ret =%d\n",ret);
	if(ret<0){
		perror("listen failen..");
	}
	
	int clientfd;
	struct sockaddr_in client;
	socklen_t len =0;
	while(1){
		printf("accept..\n");
		clientfd = accept(fd,(struct sockaddr*)&client,&len);
		printf("client fd =%d:IP=%s,PORT=%d\n",clientfd,inet_ntoa(client.sin_addr),ntohs(client.sin_port));
		pid_t pid =fork();
		if(pid==0){
			char* str = "欢迎光临...";
			ret = write(clientfd,str,strlen(str));
			printf("发送%d字节到客户端...\n",ret);
			char buf[100]="";
			while(1){
				ret = read(clientfd,buf,100);
				printf("从%d客户端读到%d字节:%s\n",clientfd,ret,buf);
				memset(buf,0,100);
				if(ret==0){
					printf("%d客户端已断开\n",clientfd);
					break;
				}
			}
			close(clientfd);
			break;
		}
	}
out:
	printf("end...");
	close(fd);
	return 0;
} */