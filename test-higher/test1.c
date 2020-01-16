#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>


int main(int argc,char*argv[]){
	pid_t pid;
	pid = fork();
	switch(pid){
		case -1:
			perror("new process failed...");
			exit(-1);
		break;
		case 0:
			for(int i=0;i<100;i++){
				pid = fork();
				if(pid ==0)break;
				printf("zombie process %dproduced\n",i);
			}
		break;
		default:
			printf("orphan process produced\n");
			sleep(10);
			exit(0);
		break;
	}
	sleep(10);
	return 0;
}
/* int main(int argc,char*argv[]){
	int size,res,fd1,fd2;
	char readbuf[20]={0};
	char tmpchar[2] ={0};
	char*r = readbuf;
	char*t = tmpchar;
	int num[100];
	int i,position=0;
	
	fd1 = open("1.txt",O_RDONLY);
	if(fd1<0){
		perror("fd1 open failed...");
		exit(1);
	}
	fd2 = open("2.txt",O_RDWR|O_CREAT,0744);
	if(fd2<0){
		perror("fd2 open failed...");
		exit(1);
	}
	size = lseek(fd1,0,SEEK_END);
	lseek(fd1,0,SEEK_SET);
	printf("size=%d\n",size);
	for(i=0;i<size;i++){
		read(fd1,tmpchar,1);
		printf("tmpchar=%s\n",tmpchar);
		position = lseek(fd1,0,SEEK_CUR);
		printf("%d\n",position);
	}

	for(;;){
		memset(readbuf,0,sizeof(readbuf));
		r = readbuf;
		for(;;){
			size = read(fd1,tmpchar,1);
			if(size<0){printf("*tmpchar=%s\n",tmpchar);break;}
			printf("size=%d\n",size);
			if(*r==10){
				break;
			}
			// *r = *t;
			r++;
			
		}
		if(size<0)break;
		printf("%s\n",readbuf);		
		num[len++]=atoi(readbuf);

		// write(fd2,readbuf,size);
		
	}
	for(i=0;i<len;i++){
		printf("num%d\n",num[i]);
	}
	
	res = close(fd1);
	if(res<0){
		perror("fd1 close failed...");
	}
	res = close(fd2);
	if(res<0){
		perror("fd1 close failed...");
	}
	return 0;
} */
/* int main(int argc,char*argv[]){
	int size,res,fd1,fd2;
	char readbuf[20]={0};
	fd1 = open(argv[1],O_RDONLY);
	if(fd1<0){
		perror("fd1 open failed...");
		exit(1);
	}
	fd2 = open(argv[2],O_RDWR|O_CREAT,0744);
	if(fd2<0){
		perror("fd2 open failed...");
		exit(1);
	}
	for(;;){
		size = read(fd1,readbuf,20);
		write(fd2,readbuf,size);
		if(size<20)break;
	}
	
	
	res = close(fd1);
	if(res<0){
		perror("fd1 close failed...");
	}
	res = close(fd2);
	if(res<0){
		perror("fd1 close failed...");
	}
	return 0;
} */
/* int main(int argc,char*argv[]){
	int size,res,fd;
	char readbuf[20]={0};
	fd = open("./123.c",O_RDONLY);
	if(fd<0){
		perror("open failed...");
		exit(1);
	}
	for(;;){
		size = read(fd,readbuf,20);
		printf("%s\n",readbuf);
		fflush(stdout);
		if(size<20)break;
	}
	
	
	res = close(fd);
	if(res<0){
		perror("close failed...");
	}
	return 0;
} */
/* int main(int argc,char*argv[]){
	FILE*fp = NULL;
	fp = fopen("./6.txt","w");
	
	printf("fp=%p\n",fp);
	int ret;
	char*buf= "hello";
	int i = 10;
	while(i--){
		fwrite(buf,1,5,fp);
		sleep(1);
	}
	fclose(fp);
} */
/* int main(int argc,char*argv[]){
	int fd,res;
	int size;
	char buf[20]="ajfdklajgk";
	char buftmp[20]={0};
	
	fd = open("./2.txt",O_CREAT|O_WRONLY,0244);
	if(fd<0){
		perror("open failed...");
		exit(1);
	}
	printf("fd =%d\n",fd);
	
	
	size = write(fd,buf,strlen(buf));
	printf("%d byte have write in buf=%s\n",size,buf);
	// res = close(fd);
	lseek(fd,0,SEEK_SET);
	fd = open("./2.txt",O_RDONLY);
	if(fd<0){
		perror("open failed...");
		exit(1);
	}
	printf("fd =%d\n",fd);
	
	size = read(fd,buftmp,5);
	printf("%d byte have read in buf=%s\n",size,buftmp);
	res = close(fd);
	if(res<0){
		perror("close failed...");
	}

	
	return 0;
} */
/* int main(int argc,char*argv[]){
	for(int i=0;i<3;i++){
		
		fprintf(stdout,"world");
		fprintf(stderr,"hello");
	}
	while(1);
	return 0;
} */
/* int main(int argc,char*argv[]){

	int i,j;
	char*p;
	for(j=0;j<argc;j++){
		p = argv[j];
		for(i=0;i<strlen(argv[j]);i++){
			printf("%c",*p);
			fflush(stdout);
			p++;
			sleep(1);
		}
	}
	printf("\n");
	return 0;
} */