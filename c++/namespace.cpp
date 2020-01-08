#include <iostream>
#include <iomanip>
#include <unistd.h>
#include <string.h>

using namespace std;
int fun(int a,int b){
	return a*a+b*b;
}
double fun(double a ,double b){
	return a*a+b*b;
}
int main(){
	cout<<"fun(2,3)="<<fun(2,3)<<endl;
	cout<<"fun(2.2,3.3)="<<fun(2.2,3.3)<<endl;
}
/* int add(int a =1,int b =2,int c=3){
	return a+b+c;
}
int main(){
	cout<<"add()"<<add(2)<<endl;
	cout<<"add()"<<add(2,3)<<endl;
	cout<<"add()"<<add(2,3,4)<<endl;
} */
/* typedef struct Stu{
	int no;
	string name;
	char gender;
	float score;
	void show(){
		cout<<no<<","<<name<<","<<gender<<","<<score<<endl;
	}
	void create_stu(string name,char gender,float score){
		static int num = 190800;
		num++;
		this->no = num;
		this->name = name;
		this->gender = gender;
		this->score = score;
	}
}stu_t;

int main(){
	stu_t* jack = NULL;
	jack = (stu_t*)calloc(sizeof(stu_t),1);
	jack->create_stu("jack",'M',89.9);
	jack->show();
	
	stu_t* rose = NULL;
	rose = (stu_t*)calloc(sizeof(stu_t),1);
	rose->create_stu("rose",'M',89.9);
	rose->show();
	free(rose);
	free(jack);
	return 0;
} */
/* template <typename U>
U max1(U a,U b){

	return (a>b)?a:b;
}
int main(){
	cout<<"int max="<<max1(3,4)<<endl;
	cout<<"float max="<<max1(3.3f,4.4f)<<endl;
	cout<<"double max="<<max1(3.3,4.4)<<endl;
	cout<<"char max="<<max1('a','b')<<endl;
	cout<<"string max="<<max1("AA","BB")<<endl;
	cout<<"string max="<<max1("BB","AA")<<endl;
	cout<<"string max="<<max1("hello","world")<<endl;
} */
/* struct my_string{
	char*p;
	int length(){
		return strlen(p);
	}
};
int main(){
	struct my_string str;
	char *p1 = (char*)calloc(20,sizeof(char));
	strcpy(p1,"hello");
	str.p =p1;
	cout<<"&p1="<<&p1<<endl;
	cout<<"p1="<<(void*)p1<<endl;
	cout<<"&str.p="<<&str.p<<endl;
	cout<<"str.p="<<(void*)str.p<<endl;
	cout<<"*(str.p+3)="<<*(str.p+4)<<endl;
	free(p1);
} */
/* int main(){

	// cout<<"input"<<endl;
	// cin>>name[0]>>name[1]>>name[2];
	// cout<<name[0]<<name[1]<<name[2]<<endl;
	string str="hello";
	string str1="\0world";
	cout<<str<<"\t"<<str.length()<<'\t'<<str.size()<<','<<sizeof(str)<<endl;
	for(int i=0;i<str.size();i++){
		cout<<str.at(i)<<flush;
		sleep(1);
	}
	if(str1.empty()){
		cout<<"kong"<<endl;
	}else{
		cout<<"bukong"<<endl;
	}
	str.append("world");
	cout<<str<<endl;

	return 0;
} */