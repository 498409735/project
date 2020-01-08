#include "server.h"


int main(int argc,char*argv[]){

	if(argc<2){
		printf("input argument have no server address!\n eg:xxx 192.168.16.128\n");
		exit(0);
	}
	int fd  = socket(AF_INET,SOCK_STREAM,0);
	if(fd<0){
		perror("socket failed...");
		exit(1);
	}
	/* if(setsockopt(fd,SOL_SOCKET,SO_REUSEADDR,&on,sizeof(int))<0)
		exit(-1); */
	int on =1;
	setsockopt(fd,SOL_SOCKET,SO_REUSEADDR,&on,sizeof(int));
	/* struct sockaddr_in server;
	server.sin_family = AF_INET;
	server.sin_port = htons(8990);
	server.sin_addr.s_addr = inet_addr("192.168.16.128");
	int bind(int sockfd, const struct sockaddr *addr,
                socklen_t addrlen); */

	struct sockaddr_in server;
	server.sin_family = AF_INET;
	server.sin_port = htons(8990);
	server.sin_addr.s_addr = inet_addr(argv[1]);
	if(bind(fd,(struct sockaddr*)&server,(socklen_t)sizeof(struct sockaddr_in))<0){
		perror("bind faile..");
		close(fd);
		exit(1);
	}
	if(listen(fd,10)<0){
		perror("listen faile..");
		close(fd);
		exit(1);
	}
	
	int client_num =0;
	int client_fd;
	struct sackaddr_in client_addr[100];
	
	while(1){
		client_fd = accept(fd,(struct sockaddr)client_addr[client_num],(socklen_t)sizeof());
	}
	
	close(fd);
	return 0;
}