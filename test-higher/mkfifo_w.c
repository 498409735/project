#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <pthread.h>

/* char chat_end=0;
void*chat_read(void*arg){
	int fd = ope
}
int main(){
	pthread_t thread;
	pthread_create(&thread,NULL,chat_read,NULL);
	int fd = open("./ppp",O_CREAT|O_RDWR);
	
} */
#define WR 1
#define RD 0
char* path1 = "/tmp/www";
char* path2 = "/tmp/rrr";
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
	closeflag = 1;
	// close(fd2);
	
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
	pid_t pid;
	pid = fork();
	if(pid==0){
		int fd = open("./uuu",O_RDONLY);
		printf("fd =%d\n",fd);
		int size;
		char buf [20]="";

		printf(" reading wait...\n");
		
		size = read(fd,buf,20);
		printf("%d byte have read %s\n",size,buf);
		close(fd);
		fd = open("b.txt",O_WRONLY|O_CREAT,0666);
		write(fd,buf,size);
		close(fd);
	}
	if(pid>0){
		char buf[20]="";
		int fd = open("a.txt",O_RDONLY);
		if(fd<0){
			perror("open a.txt failed");
			exit(-1);
		}
		int size = read(fd,buf,20);
		printf("%d byte have read\n",size);
		close(fd);
		
		if(access("uuu",F_OK|R_OK|W_OK)!=0){
			perror("pipo file error");
			exit(-1);
		}
		fd = open("uuu",O_WRONLY);
		printf("prepare write...\n");
		write(fd,buf,size);
		close(fd);
		wait(pid);
		exit(0);
	}
} */
/* int main(int argc,char*argv[]){
	char* path = "/tmp/uuu";
	int fd = open(path,O_WRONLY);
	printf("fd =%d\n",fd);
	int size;
	char  buf[30]="";
	getstring(buf,20);

		printf("写之前...\n");	
	sleep(1);
	size = write(fd,buf,strlen(buf));
	printf("%d byte have write\n",size);

	// while(1);
	// char*string="0123\n";
	// size = write(fd,str,strlen(string));
	// printf("%d byte have write\n",size);
	close(fd);
	return 0;
} */
/* int main(int argc,char*argv[]){
	
	int fd[2];
	pipe(fd);
	
	pid_t pid;
	pid = fork();
	if(pid==0){
		int ret = 0;
		char buf[10] ="";
		printf("我是子进程,正在等待父进程\n");
		ret = read(fd[0],buf,10);
		printf("我是子进程,从父进程读到%d字节%s\n",ret,buf);
		close(fd[0]);
		exit(1);
	}
	if(pid>0){
		char*str ="12434294u";
		int i=10;
		while(i--){
			putchar('.');fflush(stdout);sleep(1);
		}
		write(fd[1],str,11);
		printf("我是父进程,写了11个数据给子进程\n");
		close(fd[1]);
		exit(1);
	}
	return 0;
}  */
/* int main(int argc,char*argv[]){
	FILE*fp=NULL;
	fp = popen("cat > 2.txt","w");
	
	char *str ="sdfjasrui1234\n";
	fwrite(str,strlen(str),1,fp);
	pclose(fp);
	return 0;
}  */
/* int main(int argc,char*argv[]){
	FILE*fp=NULL;
	fp = popen("uname -a","w");
	char buf[100]={0};
	fgets(buf,100,fp);
	pclose(fp);
	return 0;
} */