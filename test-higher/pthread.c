#include <stdio.h>
#include <pthread.h>
#include <stdlib.h>
#include <unistd.h>
#include <semaphore.h>
#include <fcntl.h>
#include <signal.h>

int sum=0;
sem_t sem;
pthread_mutex_t mutex = 
/* void*thread_fun(void*arg){
	
}
int main(int argc,char*argv[]){
	pthread_t pthread_id;
	pthread_attr_t attr;
	pthread_attr_init(&attr);
	pthread_attr_setdetachstate(&attr,PTHREAD_CREATE_DETACHED);
	pthread_create(&pthread_id,attr,thread_fun,NULL);
	pthread_join(pthread_id,NULL);
	pthread_attr_destroy(&attr);
} */
/* int num = 0;
sem_t sem;
pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;
void* thread_fun1(void*arg){
	while(1){
		if(num<3){
			printf("挂起thread1...\n");
			sem_wait(&sem);
		}
		pthread_mutex_lock(&mutex);
		printf("num=%dthread1\n",++num);
		pthread_mutex_unlock(&mutex);		
		sleep(1);
	}
	return NULL;
}
void* thread_fun2(void*arg){
	while(1){
		
		pthread_mutex_lock(&mutex);
		printf("num=%d thread2\n",++num);
		pthread_mutex_unlock(&mutex);
		if(num==3)sem_post(&sem);
		sleep(1);
	}
	return NULL;
}
int main(int argc,char* argv[]){

	pthread_t pthread_id[2];
	pthread_create( &pthread_id[0],NULL,thread_fun1,NULL);
	pthread_create( &pthread_id[1],NULL,thread_fun2,NULL);

	while(1);

	return 0;
} */  
/* void catch_sig(int sig){
	puts("hello");
	fflush(stdout);
	sleep(1);
	alarm(1);
}
void* thread_fun(void*arg){
	signal(SIGALRM,catch_sig);
	alarm(1);
	while(1){
		putchar('.');
		fflush(stdout);
		sleep(1);
	}	
	return (void*)0;
}
int main(int argc,char* argv[]){

	pthread_t pthread_id;
	int fd =open("1.txt",O_CREAT|O_RDWR,0666);
	
	pthread_create( &pthread_id,NULL,thread_fun,(void*)&fd);
	
	// int i =10;
	dup2(fd,1);
	while(1){
		putchar('*');
		fflush(stdout);
		sleep(1);
	}
	 
	int ret;
	pthread_cancel(pthread_id);
	pthread_join(pthread_id,(void*)&ret);
	printf("pthread close %d\n",ret);
	// pthread_attr_destroy(&attr);
	return 0;
}  */
/* void* thread_fun(void*arg){
	// int 
	while(1){
		putchar('.');
		fflush(stdout);
		sleep(1);
	}	
	return (void*)0;
}
int main(int argc,char* argv[]){

	pthread_t pthread_id;
	pthread_attr_t attr;
	pthread_attr_init(&attr);
	// pthread_attr_setdetachstate(&attr,PTHREAD_CREATE_DETACHED);
	pthread_create( &pthread_id,&attr,thread_fun,NULL);
	
	int i =10;
	while(i--){
		putchar('*');
		fflush(stdout);
		sleep(1);
	}
	 
	int ret;
	pthread_cancel(pthread_id);
	pthread_join(pthread_id,(void*)&ret);
	printf("pthread close %d\n",ret);
	pthread_attr_destroy(&attr);
	return 0;
}  */
/* int num =0;
sem_t sem;
void* thread_fun1(void*arg){
	while(1){
		sem_wait(&sem);
		num++;
		printf("%0x thread num=%d\n",(int)pthread_self(),num);
		sleep(1);
	}
	
	return NULL;
}
void* thread_fun2(void*arg){
	while(1){
		num++;
		if(num>3)sem_post(&sem);;
		printf("%0x thread num=%d\n",(int)pthread_self(),num);
		sleep(1);
	}
	
	return NULL;
}
int main(int argc,char* argv[]){
	sem_init(&sem,0,0);
	pthread_t pthread_id[2];
	pthread_create( &pthread_id[0],NULL,thread_fun1,NULL);
	pthread_create( &pthread_id[1],NULL,thread_fun2,NULL);
	 
	void* ret;
	pthread_join(pthread_id[0],&ret);
	pthread_join(pthread_id[1],&ret);
	sem_destroy(&sem);
	return 0;
} */
/* #include <pthread.h>

       int pthread_create(pthread_t *thread, const pthread_attr_t *attr,
                          void *(*start_routine) (void *), void *arg);
 */
/* typedef struct Sort_num{
	int num[10];
	int len;
}sort_num_t;

void* pthread_fun(void*arg){
	int i,j;
	int *p = NULL;
	sort_num_t* data = (sort_num_t*)arg;
	int length = data->len;
	int tmp;
	
	for(i=0;i<length-1;i++){
		p = data->num;
		sleep(1);
		for(j=0;j<length-1;j++){
			if(*(p+j)>*(p+j+1)){
				// printf("交换前:%d %d\n",*(p+j),*(p+j+1));
				tmp 		= *(p+j);
				*(p+j) 		= *(p+j+1);
				*(p+j+1)	= tmp;
				putchar('@');
				fflush(stdout);
				// printf("交换后%d %d\n",*(p+j),*(p+j+1));
			}
		}
	}
	return arg;
}
int main(int argc,char* argv[]){
	int i,j=10;
	pthread_t pthreadid;
	sort_num_t new_arr = {0};
	
	for(i=0;i<10;i++){
		new_arr.num[i] = rand()%100;
	}
	new_arr.len = 10;
	for(i=0;i<new_arr.len;i++){
		printf("%d ",new_arr.num[i]);
	}
	printf("\n");
	printf("程序开始运行\n");
	pthread_create(&pthreadid,NULL,pthread_fun,(void*)&new_arr);
	printf("创建线程成功\n");
	while(j--){
		putchar('*');
		sleep(1);
		fflush(stdout);
	}
	
	sort_num_t* num_last;
	pthread_join(pthreadid,(void**)&num_last);
	
	for(i=0;i<num_last->len;i++){
		printf("%d ",num_last->num[i]);
	}
	printf("\n");	
	
} */