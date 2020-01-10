#include <iostream>
#include <iomanip>
#include <unistd.h>
#include <string.h>
#include <math.h>

using namespace std;
class Point{
public:
	Point(int x_tmp=0,int y_tmp=0):
	x(x_tmp),y(y_tmp)
	{
		cout<<"构造点"<<x<<y<<endl;
	}
	void setxy(int x_tmp = 0,int y_tmp=0){
		this->x = x_tmp;
		this->y = y_tmp;
	}
	int getx()const{
		return x;
	}
	int gety()const{
		return y;
	}
private:
	int x,y;
};
class Line{
public:
	Line(Point&start,Point&end):
	start_point(start),end_point(end)
	{
		// start_point.setxy(start.getx(),start.gety());
		// end_point.setxy(end.getx(),end.gety());
		cout<<"构造"<<start_point.getx()<<","<<start_point.gety()<<"---"
			<<end_point.getx()<<","<<end_point.gety()<<endl;
	}
	void set_point(Point&start,Point&end){
		start_point.setxy(start.getx(),start.gety());
		end_point.setxy(end.getx(),end.gety());
	}
	Point get_poit(string pos)const{
		if(pos =="start"){return start_point;}
		if(pos == "end"){return end_point;}
		cout<<"start"<<start_point.getx()<<","<<start_point.gety()<<"------"
			<<"end"<<end_point.getx()<<","<<end_point.gety()<<endl;
	}
	double len(){
		int detax = pow(end_point.getx()-start_point.getx(),2);
		int detay = pow(end_point.gety()- start_point.gety(),2);
		return sqrt(detax+detay);
	}
private:
	Point start_point;
	Point end_point;
};
int main(){
	Point p1(0,0),p2(3,4);
	Line l1(p1,p2);
	cout<<l1.len()<<endl;
	return 0;
}
/* class CAR{
private:
	string brand;
	int weight;
public:
	CAR(string brand_tmp,int weight_tmp);
	~CAR();
	void set(string brand_tmp,int weight_tmp);
	void get();
};
CAR::CAR(string brand_tmp,int weight_tmp)
:brand(brand_tmp),weight(weight_tmp)
{
	cout<<"构造车"<<endl;
}
CAR::~CAR(){
	cout<<"析构"<<endl;
}
void CAR::get(){
	cout<<this->brand<<this->weight<<endl;
}
void CAR::set(string brand_tmp,int weight_tmp){
	this->brand = brand_tmp;
	this->weight = weight_tmp;
}
int main(){
	CAR jack("lis",99);
	jack.get();
	jack.set("jack",98);
	jack.get();
} */
/* class STU{
private:
	char* name;
	char gender;
	float score;
public:
	STU(const char*name,char gender,float score);
	void show()const;
	~STU();
};
STU::STU(const char*name,char gender,float score)
:gender(gender),score(score)
{
	if(name!=NULL){
		this->name = new char[strlen(name)+1];
	}else{
		this->name = new char[1];
	}
	strcpy(this->name,name);
	cout<<"构造生成"<<endl;
}
STU::~STU(){
	cout<<this->name<<"析构"<<endl;
	delete []this->name;
}
void STU::show()const{
	cout<<"name:"<<name<<gender<<score<<endl;
}

int main(){
	STU jack("jack",'F',89.2);
	jack.show();
	return 0;
} */



/*int fun(int a,int b){
	return a*a+b*b;
}
double fun(double a ,double b){
	return a*a+b*b;
}
int main(){
	cout<<"fun(2,3)="<<fun(2,3)<<endl;
	cout<<"fun(2.2,3.3)="<<fun(2.2,3.3)<<endl;
}*/
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
