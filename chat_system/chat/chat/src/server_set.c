#include "head.h"

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
/* ********************************
@parameter:	
@return:
@explain:	从配置文件中读取ip,端口
 */
int port_rdwr(u16* port,char* ip,int rwflag){
	u16 port_tmp;
	char ip_tmp[20]={0};
	port_tmp = *port;
	strncpy(ip_tmp,ip,20);
	char buf_tmp[50]= {0};
	
	FILE* fp = fopen("./doc/profile","w+");
	if(ferror(fp)!=0){
		perror("open server profile failed...");
		return -1;
	}
	if(rwflag==WR){
		pritnf("请输入ip地址\n");
		getstring(ip_tmp,20);
		
		printf("请输入port值,如8990,8000等");
		scanf("%d",&port_tmp);
		while(getchar()!=10);
		sprintf(buf_tmp,"SERVER_IP =%s\n",ip_tmp);
		fputs(buf_tmp,fp);
		sprintf(stdout,"PORT =%d\n",port_tmp);
		fputs(buf_tmp,fp);
		printf("地址,端口写入成功\n");
	}else{
		fgets(buf_tmp,fp);
		strsep(buf_tmp,"=");
		ip_tmp = atoi(buf_tmp);
		fgets(buf_tmp,fd);
		strsep(buf_tmp,"=");
		strncpy(ip_tmp,buf_tmp,20);
		
		
		
		
	}
	fclose(fp);
}