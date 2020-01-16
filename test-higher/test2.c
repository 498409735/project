#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/wait.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>


/* int main(int argc,char*argv[]){
	pid_t pid;
	pid = fork();
	if(pid<0){
		perror("new process failed");
		exit(1);
	}
	switch(pid){
		case 0:
		
		break;
		default:
		printf("父进程退出%d\n",getpid());
		exit(1);
		break;
	}
} */
/* int main(int argc,char*argv[]){
	pid_t pid;
	// int num =5;
	pid = fork();
	if(pid<0){
		perror("fork failed...");
		exit(1);
	}
	if(pid>0){
		// sleep(10);
		// int wpid=0,ret;
		printf("我父进程%d,over\n",getpid());
		exit(1);
	}
	int fd;
	char* str="我是守护进程";
	setsid();
	chdir("/");
	umask(0);
	for(int i=0;i<65536;i++){
		close(i);
	}
	while(1){
		fd = open("/tmp/1.txt",O_RDWR|O_CREAT|O_APPEND,0766);
		write(fd,str,strlen(str));
		printf("fork failed...");
		close(fd);
		sleep(5);
	}
	return 0;
} */
/* int main(int argc,char*argv[]){
	pid_t pid;
	// int num =5;
	pid = fork();
	if(pid==0){
		int i = 5;
		
		printf("我是子进程,pid=%d,我父亲ID为%d\n",getpid(),getppid());
		while(i--){
			printf("%d\n",i);
			sleep(1);
		}
		printf("子进程,pid=%d,我父亲ID为%d\n",getpid(),getppid());
		exit(1);
	}
	if(pid>0){
		sleep(10);
		// int wpid=0,ret;
		printf("我父进程%d,over\n",getpid());
	}
	return 0;
} */
/* int main(int argc,char*argv[]){
	pid_t pid;
	int num =5;
	for(int i=0;i<3;i++){
		pid = fork();
		if(pid==0)break;
	}
	if(pid==0){
		printf("我是子进程,pid=%d\n",getpid());
		while(num--){
			sleep(1);
		}
	}
	if(pid>0){
		sleep(1);
		int wpid=0,ret;
		printf("请输入要等待的子进程:\n");
		scanf("%d",&wpid);
		printf("正在等待子进程%d结束\n",wpid);
		ret = waitpid(wpid,NULL,WNOHANG);
		// ret = waitpid(wpid,NULL,WUNTRACED);
		printf("等到了子进程:%d\n",ret);
	}
	return 0;
} */
/* int main(int argc,char*argv[]){
	pid_t pid;
	pid_t wpid;
	pid = fork();
	// printf("pid=%d\n",pid);
	switch(pid){
		case -1:
		printf("error\n");
		break;
		case 0:
		{
			int i =10;
			printf("我是子进程,pid=%d\n",getpid());
			while(i--){
				printf("*");
				sleep(1);
				fflush(stdout);
			}
			exit(12) ;
		}
		break;
		default:
		{
			int status = 0;
			printf("我是父进程,pid=%d\n",getpid());
			wpid = wait(&status);
			printf("wpid=%d,status=%d\n",wpid,WEXITSTATUS(status));
		}
		break;
	}
	return 0;
} */
/* int main(int argc,char*argv[]){
	int ret;
	int fd;
	int savefd,savefd2;
	savefd = dup(1);
	savefd2 = dup(2);
	fd = open("myshell.txt",O_RDWR|O_CREAT,0777);
	char buf[10]={0};
	while(1){
		dup2(savefd,1);
		dup2(savefd2,2);
		printf("请输入命令\n");
		fgets(buf,10,stdin);
		if(strncmp(buf,"end",3)==0)break;
		dup2(fd,1);
		dup2(fd,2);
		ret = system(buf);
		printf("ret=%d\n",ret);
	}
	 
}*/
/* int main(int argc,char*argv[]){
	int ret;
	char buf[10]={0};
	while(1){
		printf("请输入命令\n");
		fgets(buf,10,stdin);
		if(strncmp(buf,"end",3)==0)break;
		ret = system(buf);
		printf("ret=%d\n",ret);
	}
	return 0;
} */

int main(int argc,char*argv[]){
	pid_t pid;
	for(int i=0;i<3;i++){
		pid = fork();
		if(pid==0)break;
	}
	
	sleep(10);
	// if(pid==0)system("ps alf");
	// sleep(2);
	// return 0;
	// int fd;
	// fd = open("./4.txt",O_RDWR|O_CREAT,0777);
	// if(fd<0){
		// perror("open failed");
	// }
	// int ret;
	// char*buf= "hello";
	// int i = 10;
	// while(i--){
		// ret = write(fd,buf,5);	
		// write(1,"asd",4);
		// printf("ret = %d\n",ret);
		// sleep(1);
	// }
	// close(fd);
	// char tmpbuf[30]={0};
	// read(1,tmpbuf,15);
	// printf("tmpbuf=%s\n",tmpbuf);
	return 0;
}