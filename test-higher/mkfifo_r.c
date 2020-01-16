#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <pthread.h>

/* int main(){
	int fd =open("./ppp",O_RDWR|O_RDWR);
	printf("fd=%d\n",fd);
	char buf[100]="";
	
} */
#define WR 1
#define RD 0
char* path1 = "/tmp/rrr";
char* path2 = "/tmp/www";
int closeflag =0;
int getstring(char* str,unsigned int len){
	int pos;
	fgets(str,len,stdin);
	if(str[0]==27)return -1;
	pos = strlen(str);
	if(str[pos-1]==10)str[pos-1]=0;
	return pos-1;
}
void* thread_fun(void*arg){
	int flag = *(int*)arg;
	char wr_buf[100] = "";
	char rd_buf[100] = "";
	int size;
	int fd1,fd2;
	if(flag==WR){
		fd1 = open(path1,O_WRONLY);
		while(1){
			printf("请输入聊天内容:\n");
			memset(wr_buf,0,100);
			size = getstring(wr_buf,100);
			
			write(fd1,wr_buf,size);
			if(strcmp(wr_buf,"end")==0)break;
			printf("send OK\n");
			sleep(1);
		}	
		close(fd1);	
	}else{
		
		fd2 = open(path2,O_RDONLY);
		while(1){
			printf("prepare to recieve...\n");
			memset(rd_buf,0,100);
			size = read(fd2,rd_buf,100);
			if(strcmp(rd_buf,"end")==0)break;
			printf("%d byte have read %s\n",size,rd_buf);			
		}
		close(fd2);
	}
	closeflag =1;
	
	
	return NULL;
}
int main(int argc,char*argv[]){
	
	if(access(path1,F_OK)!=0){
		mkfifo(path1,0666);
		printf("mk pipo file success\n");
	}
	if(access(path2,W_OK)!=0){
		chmod(path2,0666);
		printf("change mode success\n");
	}
	
	if(access(path2,F_OK)!=0){
		mkfifo(path2,0666);
		printf("mk pipo file success\n");
	}
	if(access(path2,R_OK)!=0){
		chmod(path2,0666);
		printf("change mode success\n");
	}
	pthread_t pthread_id[2];
	int thread1_flag = WR;
	int thread2_flag = RD;
	pthread_create(&pthread_id[0],NULL,thread_fun,(void*)&thread1_flag);
	pthread_create(&pthread_id[1],NULL,thread_fun,(void*)&thread2_flag);
	while(1){
		if(closeflag==1){
			pthread_cancel(pthread_id[0]);
			pthread_cancel(pthread_id[1]);
			break;
		}
	}
	
	pthread_join(pthread_id[0],NULL);
	pthread_join(pthread_id[1],NULL);


	return 0;
} 
/* int main(int argc,char*argv[]){
	char* path = "/tmp/uuu";
	if(access(path,F_OK)!=0){
		mkfifo(path,0666);
		printf("mk pipo file success\n");
	}
	if(access(path,R_OK)!=0){
		chmod(path,0666);
		printf("change mode success\n");
	}
	int fd = open(path,O_RDONLY);
	printf("fd =%d\n",fd);
	int size;
	char buf [20]="";

			printf("no string...\n");
	// while(1);
	size = read(fd,buf,20);
	printf("%d byte have read %s\n",size,buf);
	

	close(fd);
	return 0;
} */