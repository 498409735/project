#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/wait.h>


int main(int argc,char*argv[]){
	int pipefd[2];
	int fd;
	pipe(pipefd);
	pid_t pid;
	pid = fork();
	if(pid==0){
		close(pipefd[1]);
	
		int size;
		char buf [20]="";

		printf(" child reading wait...\n");
		
		size = read(pipefd[0],buf,20);
		printf("child %d byte have read %s\n",size,buf);
		close(pipefd[0]);
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
		printf("num byte have read\n");
		close(fd);
		
		close(pipefd[0]);
		printf("prepare write...\n");
		sleep(3);
		write(pipefd[1],buf,size);
		close(pipefd[1]);		
		wait(NULL);
		exit(0);
	}
}
/* int main(int argc,char*argv[]){
	int fd = open("./uuu",O_WRONLY);
	printf("fd =%d\n",fd);
	int size;
	char*str="aklsfdja\n";
	printf("写之前...\n");	
	sleep(1);
	size = write(fd,str,strlen(str));
	printf("%d byte have write\n",size);
	char*string="0123\n";
	size = write(fd,str,strlen(string));
	printf("%d byte have write\n",size);
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