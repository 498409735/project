#include <iostream>
#include <iomanip>
#include <unistd.h>
#include <string.h>
#include <math.h>

using namespace std;

/*  class Date{
public:
	Date(const int y = 1978,const int m = 1,const int d =1)
	:year(y),month(m),day(d){
		cout<<"构造日期"<<this->year<<"-"<<this->month<<"-"<<this->day<<endl;
	}
	Date(const Date&other){
		if((other.year==this->year)&&(other.month==this->month)&&(other.day==this->day))return;
		this->year = other.year;this->month = other.month;this->day = other.day;
		cout<<"copy "<<this->year<<"-"<<this->month<<"-"<<this->day<<endl;
	}
	void show()const{
		cout<<"日期为:"<<year<<"-"<<month<<"-"<<day<<endl;
	}
  	// Date operator++(){//这几行有问题,i++应该是先赋值后运算,这几行无法完成
		// cout<<"++i"<<endl;
		// Date tmp = *this;
		// this->year ++;this->month++;this->day++;
		// return tmp;
	// }
	// Date&operator++(int){
		// cout<<"i++"<<endl;
		// this->year++;this->month++;this->day++;
		// return *this;
	// }  
	Date &operator++(){
		cout<<"++i"<<endl;
		this->year++;this->month++;this->day++;
		return *this;
	}
	Date operator++(int){
		cout<<"i++"<<endl;
		Date tmp = *this;
		this->year ++;this->month++;this->day++;
		return tmp;
	} 
	~Date(){
		cout<<"date delete"<<endl;
	}
private:
	int year,month,day;
		
};
int main(){
	Date d1(1970,2,10);
	Date d2(1966,1,3);
	Date d3;
	d3 = d1++;
	cout<<"d3:"<<endl;
	d3.show();
	cout<<"d1:"<<endl;
	d1.show();
	d3 = ++d1;
	cout<<"d3:"<<endl;
	d3.show();
	cout<<"d1:"<<endl;
	d1.show();
	return 0;
}   */
class Mystring{
public:
	Mystring(const char* str = NULL){
		if(str==NULL){
			pData = new char[1];
		}else{
			pData = new char[strlen(str)+1];
			strcpy(pData,str);
		}
		cout<<"mystring initial"<<endl;
	}
	Mystring(const Mystring&other){
		if(strcmp(this->pData,other.pData)==0)return;
		this->pData = new char[strlen(other.pData)+1];
		strcpy(this->pData,other.pData);
		cout<<"copy string"<<endl;
	}
	char *getData()const{
		cout<<this->pData<<endl;
		return pData;
	}
	Mystring operator +(const Mystring&other){
		Mystring tmp;
		delete []tmp.pData;
		int len = strlen(this->pData)+strlen(other.pData)+1;
		tmp.pData = new char[len];
		strcpy(tmp.pData,this->pData);
		strcat(tmp.pData,other.pData);
		return tmp;
	}
	Mystring&operator=(const Mystring&other){
		strcpy(this->pData,other.pData);
		return *this;
	}
	char operator[](int n){
		return this->pData[n];
	}
	Mystring operator +=(const Mystring&other){
		Mystring tmp;
		delete []tmp.pData;
		int len = strlen(this->pData)+strlen(other.pData)+1;
		tmp.pData = new char[len];
		strcpy(tmp.pData,this->pData);
		strcat(this->pData,other.pData);
		return tmp;
	}
	bool operator>(const Mystring&other){
		if(strcmp(this->pData,other.pData)>0)return true;
		else return false;
	}
	bool operator>=(const Mystring&other){
		if(strcmp(this->pData,other.pData)<0)return false;
		else return true;
	}
	bool operator<(const Mystring&other){
		if(strcmp(this->pData,other.pData)<0)return true;
		else return false;
	}
	bool operator<=(const Mystring&other){
		if(strcmp(this->pData,other.pData)>0)return false;
		else return true;
	}
	~Mystring(){
		cout<<"mystring delete"<<endl;
		delete []pData;
	}
private:
	char* pData;
};
int main(){
	Mystring str1("hello");
	Mystring str2("eorld");
	Mystring str3 = str1+str2;
	str1.getData();
	str2.getData();
	str3.getData();
	str3+=str2;
	str3.getData();
	cout<<str3[2]<<endl;
	bool tmp = str1>str2;
	cout<<"str1>str2 ? "<<tmp<<endl;
	tmp = str1>=str2;
	cout<<"str1>=str2 ? "<<tmp<<endl;

}
/* class Cube{
public:
	Cube(const unsigned int length_tmp =1,const unsigned int width_tmp =1,const unsigned int high_tmp=1)
	:length(length_tmp),width(width_tmp),high(high_tmp){
		cout<<"Cube initial "<<"length:"<<this->length<<" width:"<<this->width<<" high:"<<this->high<<endl;
	}
	~Cube(){
		cout<<"Cube delete"<<endl;
	}
	bool operator<(const Cube&other){
		if(this->length*this->width*this->high<other.length*other.width*other.high)return true;
		else return false;
	}
private:
	unsigned int length;
	unsigned int width;
	unsigned int high;
};
int main(){
	Cube c1(2,3,4);
	Cube c2(3,4,5);
	bool tmp =c1<c2;
	cout<<tmp<<endl;
	tmp = c2<c1;
	cout<<tmp<<endl;
	return 0;
	
} */
/* class Worker{
public:
	Worker(string name_tmp = "zhangsan",string job_tmp = "programer")
	:name(name_tmp),job(job_tmp){
		
		cout<<"new worker added"<<this->name<<" "<<this->job<<endl;
	}
	~Worker(){
		cout<<"worker delete"<<endl;
	}
	bool operator!=(const Worker&other){
		if(this->name==other.name&&this->job==other.job)return false;
		else return true;
	}
private:
	string name;
	string job;
};
int main(){
	Worker w1("zhangsan","programer");
	Worker w2("zhangsan","programer");
	Worker w3("lisi","teacher");
	bool tmp = w1!=w2;
	cout<<tmp<<endl;
	tmp = w1!=w3;
	cout<<tmp<<endl;
	return 0;
} */
/* class Date{//0-11:1-12月;0-30:1-31号;
public:
	Date(const unsigned short year_tmp = 1970,const unsigned short month_tmp = 1,const unsigned short day_tmp =1)
	:year(year_tmp),month(month_tmp),day(day_tmp){
		this->month 	= this->month%12;
		this->day 		= this->day%31;
		cout<<"date initial:"<<this->year<<"-"<<this->month+1<<"-"<<this->day+1<<endl;
	}
	~Date(){
		// cout<<"date delete"<<endl;
	}
	Date operator-(const Date& other){
		Date tmp;
		tmp.year 	= this->year - other.year;
		tmp.month 	= this->month - other.month;
		tmp.day		= this->day - other.day;
		
		tmp.month 	= tmp.month%12;
		tmp.day		= tmp.day%31;
		return tmp;
	}
	Date operator++(){
		this->year++;
		this->month++;
		this->day++;
		this->month 	= this->month%12;
		this->day		= this->day%31;
		return *this;
	}
	Date operator++(int){
		Date tmp;
		tmp.year 	= this->year++;
		tmp.month 	= this->month++;
		tmp.day		= this->day++;
		
		tmp.month 	= tmp.month%12;
		tmp.day		= tmp.day%31;
		this->month 	= this->month%12;
		this->day		= this->day%31;
		return tmp;
	}
	Date operator--(){
		this->year--;
		this->month--;
		this->day--;
		this->month 	= this->month%12;
		this->day		= this->day%31;
		return *this;
	}
	Date operator--(int){
		Date tmp;
		tmp.year 	= this->year--;
		tmp.month 	= this->month--;
		tmp.day		= this->day--;
		tmp.month 	= tmp.month%12;
		tmp.day		= tmp.day%31;
		this->month 	= this->month%12;
		this->day		= this->day%31;

		return tmp;
	}
	void show(){
		cout<<"Date:"<<this->year<<"-"<<this->month+1<<"-"<<this->day+1<<endl;
	}
private:
	unsigned short year;
	unsigned short month;
	unsigned short day;
};
int main(){	
	Date d1(1995,12,30);
	Date d2(1994,11,10);
	Date d3 = d1-d2;
	d3.show();
	++d3;
	d3.show();
	d3--;
	d3.show();
	return 0;
} */
/* class Complex{
public:
	Complex(const int r = 0,const int i= 0)
	:real(r),img(i){
		cout<<"complex initial ("<<real<<","<<img<<")"<<endl;
	}
	Complex(const Complex&other){
		if((other.real==this->real)&&(other.img==img))return;
		real = other.real;
		img = other.img;
		cout<<"complex copy ("<<real<<","<<img<<")"<<endl;
	}
	Complex operator + (const Complex&other){
		Complex tmp;
		tmp.real = this->real+other.real;
		tmp.img = this->img +other.img;
		return tmp;
	}
	Complex operator - (const Complex&other){
		Complex tmp;
		tmp.real = this->real-other.real;
		tmp.img = this->img -other.img;
		return tmp;
	}
	Complex operator ++(int){
		Complex tmp = *this;
		this->real++;
		this->img++;
		return tmp;
	}
	Complex &operator ++(){//++c1 c1.operator++()
		this->real++;
		this->img++;
		return *this;
	}
	Complex operator --(int){
		Complex tmp = *this;
		this->real--;
		this->img--;
		return tmp;
	}
	Complex &operator --(){
		this->real--;
		this->img--;
		return *this;
	}
	void print()const{
		cout<<"("<<real<<","<<img<<")"<<endl;
	}
	bool operator==(const Complex &tmp){
		
		if(this->real==tmp.real&&this->img==tmp.img)return true;
		else return false;
	}
private: 
	int real,img;
};
int main(){
	Complex c1(1,1),c2(2,2);
	Complex c3 = c1+c2;
	c3.print();
	c3 = c1-c2;
	c3.print();
	c3++;
	c3.print();
	
	if(c3==c2){
		cout<<"yes"<<endl;
	}else {
		cout<<"no"<<endl;
	}
	bool a =c3==c1;
	cout<<a<<endl;
	c3.operator++();
	c3.print();
	++c3;
	c3.print();
	c3--;
	c3.print();
	--c3;
	c3.print();
	return 0;
} */
/* class STU{
public:
	STU(const int id_tmp,const float score_tmp)
	:id(id_tmp),score(score_tmp){
		cout<<"student added id ="<<this->id<<" score ="<<this->score<<endl;
	}
	float get_score()const{
		return score;
	}
	int get_id()const{
		return id;
	}
private:
	int id;
	float score;
};
void my_max( STU*p,int n){
	STU *a =p;
	for(int i=0;i<n;i++){
		if(p->get_score()<a->get_score()){
			p = a;
		}
		a++;
	}
	cout<<"the max is:"<<p->get_score()<<"ID:"<<p->get_id()<<endl;
}
int main(){
	STU stu[3] = {STU(1000,80),STU(1001,90),STU(1002,87)};
	my_max(stu,3);
	return 0;
} */
/* class Employee{
public:
	Employee(const int id,const string name_tmp)
	:m_id(id),name(name_tmp){
		total++;
		
	}
	Employee(const Employee&other){
		if(other.m_id== this->m_id)return;
		this->name = other.name;
	}
	~Employee(){
		cout<<"删除员工"<<endl;
	}
	void show(){
		cout<<"工号:"<<this->m_id<<" 姓名:"<<this->name<<",总人数:"<<this->total<<endl;
	}
	static void count(){
		cout<<"总人数:"<<total<<endl;
	}
private:
	int m_id;
	string name;
	static int total;
};
int Employee::total = 0;
int main(){
	Employee zhangsan(100,"zhangsan");
	zhangsan.show();
	zhangsan.count();
	return 0;
} */
/* class Girl{
public:
	
	Girl(string name_tmp ,string wechat_tmp,unsigned short age_tmp =18,unsigned int selary_tmp =200)
	:age(age_tmp),selary(selary_tmp)
	{
		this->name = name_tmp;
		this->wechat = wechat_tmp;
		cout<<"girl initial"<<endl;
	}
	~Girl(){
		cout<<"girl delete"<<endl;
	}
	void myinfo(){
		cout<<this->name<<" "<<this->age<<" "<<this->selary<<" "<<this->wechat<<endl;
	}
	friend class Boy;
private:
	unsigned short age;
	string name;	
	string wechat;
	unsigned int selary;	
};
class Boy{
public:
	// class Girl;
	
	Boy(string name_tmp ,string wechat_tmp,unsigned short age_tmp =18,unsigned int selary_tmp =200)
	:age(age_tmp),selary(selary_tmp)
	{
		this->name = name_tmp;
		this->wechat = wechat_tmp;
		cout<<"boy initial"<<endl;
	}
	~Boy(){
		cout<<"boy delete"<<endl;
	}
	void myinfo(){
		cout<<this->name<<" "<<this->age<<" "<<this->selary<<" "<<this->wechat<<endl;
	}
	void mygirlinfo(Girl& gl);
	
private:
	unsigned short age;
	string name;	
	string wechat;
	unsigned int selary;
	
};
void Boy::mygirlinfo(Girl& gl){
	cout<<"girlfriend selary is"<<gl.selary<<endl;
}
int main(){
	Boy jack("jack","444",18,200);
	Girl rose("rose","555",17,200);
	rose.myinfo();
	jack.myinfo();
	jack.mygirlinfo(rose);
	return 0;
} */
/* class Point{
public:
	Point(int x_tmp = 0,int y_tmp =0):x(x_tmp),y(y_tmp){
		cout<<"new point ("<<this->x<<","<<this->y<<")"<<endl;
	}
	~Point(){
		// cout<<"point delete"<<endl;
	}
	int x;
	int y;
};
class Rectangle{
public:
	Rectangle(Point& lt_tmp,Point& rb_tmp):LTpoint(lt_tmp),RBpoint(rb_tmp){
		cout<<"new rectangle initial:"<<endl;
	}
	~Rectangle(){
		cout<<"rectangle delete"<<endl;
	}
	void set_LT(Point lt_tmp);
	void set_RB(Point rb_tmp);
	Point get_lt();
	Point get_rb();
	double area();
private:
	Point LTpoint;
	Point RBpoint;
};
void Rectangle::set_LT(Point lt_tmp=(0,0)){
	this->LTpoint = lt_tmp;
}
void Rectangle::set_RB(Point rb_tmp=(1,1)){
	this->RBpoint = rb_tmp;
}
Point Rectangle::get_lt(){
	Point tmp = this->LTpoint;
	return tmp;
}
Point Rectangle::get_rb(){
	Point tmp = this->RBpoint;
	return tmp;
}
double Rectangle::area(){
	int length = abs(this->LTpoint.x-this->RBpoint.x);
	int high = abs(this->LTpoint.y-this->RBpoint.y);
	double area = length* high;
	return area;
}
int main(){
	Point p1(1,1),p2(4,4);
	Rectangle tom(p1,p2);
	cout<<"area:"<<tom.area()<<endl;
	tom.set_LT(Point(2,2));
	cout<<"area:"<<tom.area()<<endl;
	
	Point p3 = tom.get_rb();
	cout<<"p3 x="<<p3.x<<"y="<<p3.y<<endl;
	return 0;
} */

/* class STU{
public:
	int num;
	float score;
};
void my_max(STU*st,int len){
	int tmp =0;;
	for(int i=0;i<len;i++){
		
		if(st[tmp].score<st[i].score)tmp =i;
	}
	cout<<"成绩最高学生为:"<<st[tmp].num<<"成绩:"<<st[tmp].score<<endl;
}
int main(){
	int i;

	STU student[10];
	for( i=0;i<10;i++){
		student[i].num = 190801+i;
		student[i].score = rand()%100;
	}
	for(i=0;i<10;i++){
		cout<<"学号:"<<student[i].num<<" 成绩:"<<student[i].score<<endl;
	}
	my_max(student,10);
	return 0;
} */
/* class Employee{
public:
	Employee(string ,int);
	~Employee(){
		cout<<"employee delete"<<endl;
	}
	void print();
	void count();
private:
	int num;
	string name;
	static int total;
};
 int Employee::total = 0;

Employee::Employee(string name_tmp ="zhangsan",int num_tmp = 190801)
:num(num_tmp),name(name_tmp){
	this->total++;
	cout<<"当前总人数:"<<this->total<<endl;
	cout<<"new employee added"<<endl;
}
void Employee::print(){
	cout<<"工号:"<<this->num<<" 姓名:"<<this->name<<endl;
}
void Employee::count(){
	cout<<"总人数:"<<this->total<<endl;
}
int main(){
	Employee zhangsan("zhangsan",190801);
	zhangsan.print();
	zhangsan .count();
	Employee lisi("lisi",190802);
	lisi.print();
	lisi.count();
	Employee wangwu("wangwu",190803);
	wangwu.print();
	wangwu.count();
	return 0;
} */
/* class Clock{
public:
	Clock(short hour_tmp =8,short minute_tmp = 0,short second_tmp = 0)
	:hour(hour_tmp),minute(minute_tmp),second(second_tmp){
		cout<<"clock initial"<<endl;
	}
	~Clock(){
		cout<<"clock delete"<<endl;
	}
	void showtime();
	void count(short,short,short);
private:
	short hour;
	short minute;
	short second;
};
void Clock::showtime(){
	cout<<"当前时间:"<<setw(2)<<this->hour<<":"<<setw(2)<<setfill('0')<<this->minute
		<<":"<<setw(2)<<setfill('0')<<this->second<<endl;
}
void Clock::count(short hour_tmp = 0,short minute_tmp = 0,short second_tmp = 5){
	this->hour += hour_tmp;
	this->minute += minute_tmp;
	this->second += second_tmp;
	unsigned int tmp = hour_tmp*3600+minute_tmp*60+second_tmp;
	sleep(tmp);
	cout<<"时间到,请注意"<<endl;
}
int main(){
	Clock tom(8,1,2);
	tom.showtime();
	tom.count(0,0,5);
	tom.showtime();
	for(int i=0;i<10;i++){
		tom.count(0,0,1);
		tom.showtime();
	}
	return 0;
} */
/* class Employee{
public:
    Employee( int num_tmp, string name_tmp):num(num_tmp){
		this->name = name_tmp;
		cout<<"构造函数"<<endl;
	}
    static int  cout(){
        return allnum++;
    }
    void print();
    ~Employee(){
		cout<<"xi"<<endl;
    }
private:
    int num;
    string name;
    static int allnum;
};
int Employee::allnum = 0;

void Employee::print(){
	cout<<"gonghao:"<<num<<endl;
	cout<<"xingming:"<<name<<endl;
    // cout<<"工号:"<<this->num<<endl;
    // cout<<"姓名:"<<this->name<<endl;
}

int main()
{
	string tmp ="zhangsan";
	int a =2020;
    Employee pes1(a,tmp);
    
    return 0;
} */
/* class Square{
public:
	Square(double length_tmp);
	~Square();
	double area();
	Square(const Square& );
private:
	double length;
};
Square::Square(double length_tmp =1.0 ):length(length_tmp){
	cout<<"创建正方形,边长="<<length<<endl;
}
Square::~Square(){
	cout<<"删除正方形"<<endl;
}
double Square:: area(){
	double tmp = this->length*this->length;
	return tmp;
}
Square::Square(const Square& square_other){
	// if(square_other. == this){
		// cout<<"invalved copy"<<endl;
		// return;
	// }
	this->length = square_other.length;
	cout<<"copy"<<endl;
}
int main(){
	Square a(2);
	cout<<"a area ="<<a.area()<<endl;
	Square b = a;
	cout<<"b area ="<<b.area()<<endl;
	return 0;
} */
/* class Time;
class Date{
public:
	Date(int y = 1970,int m =1,int d =1):year(y),month(m),day(d){
		cout<<"gouzaoriqi"<<year<<":"<<month<<":"<<day<<endl;
	}
#ifdef test
	//	friend void print(Date d,Time t);
#else
	void print(Time t);
#endif
private:
	int year,month,day;
};
class Time{
public:
	Time(int h=0,int m=0,int s= 0):hour(h),minute(m),second(s){
		cout<<"gouzao"<<hour<<":"<<minute<<":"<<second<<endl;
	}
	friend void print(Date d,Time t);
private:
	int hour,minute,second;
};
void print(Date d,Time t){
 cout<<"Date:"<<d.year<<d.month<<d.day<<endl;
 cout<<"Time:"<<t.hour<<t.minute<<t.second<<endl;
}
 int main(){
  Date today(2020,1,10);
  Time now(17,7,45);
  print(today,now);
  return 0;
} */


/*class Complex{
public:
	Complex(double x=0,double y =0):real(x),img(y){
		cout<<"gouzao"<<"real="<<real<<"img="<<img<<endl;
	}
	void printcom(){
		cout<<"real="<<real<<"img="<<img<<endl;
	}
private:
	friend Complex add(Complex&c1,Complex&c2);
	double real;
	double img;
};
Complex add(Complex&c1,Complex&c2){
	Complex com;
	com.real = c1.real+c2.real;
	com.img = c1.img +c2.img;
	return com;
}
void fun(int&a,int&b){
	a=a+1;
	b=b+1;
}
int main(){
	Complex c1(1,2),c2(2,3);
	cout<<"****"<<endl;
	Complex c3 = add(c1,c2);
	c3.printcom();

	int a =1,b=2;
	//fun(a,b);
	//cout<<"a=,b="<<a<<b<<endl;
	return 0;
}*/




/*class A{
public:
	A(int a_tmp):a(a_tmp)
	{
		cout<<"gouzao"<<endl;
	}
	int geta()const{
		cout<<"www"<<endl;
		return a;
	}
	int geta(){
		cout<<"PPP"<<endl;
		return a;
	}
private:
	int a;
};
int main(){
	const A a(100);
	cout<<a.geta()<<endl;
	A b(102);
	cout<<b.geta()<<endl;
	return 0;


}
*/
/* class mystring{
public:
	mystring( int data = 0)
	:pdata(data){
		cout<<"gouzao"<<endl;
	}
	mystring(const mystring &other){
		this->pdata = other.pdata;
		cout<<"fuzhi"<<endl;
	}
	int data(){
		return pdata;
	}
	~mystring(){
		cout<<"xigou"<<endl;
	}
private:
	int pdata;
};
int main(){
	mystring str(100);
	cout<<str.data()<<endl;
	mystring str2  =str;
	cout<<str2.data()<<endl;
	mystring str3(str);
	cout<<str3.data()<<endl;
	return 0;
} */
/* class mystring{
public:
	mystring(const char* data=NULL){
		if(data!=NULL){
			this->pdata = new char[strlen(data)+1];
			strcpy(this->pdata,data);
		}else{
			this->pdata = new char[1];
		}
		cout<<"mystring构造"<<endl;
	}
	mystring(const mystring &other){
		this->pdata = new char[strlen(other.pdata)+1];
		strcpy(this->pdata,other.pdata);
		cout<<"mystring复制构造"<<endl;
	}	
	~mystring(){
		delete []pdata;
		cout<<"mystring被析构了"<<endl;
	}
	char*data(){
		return pdata;
	}
private:
	char*pdata;
};
int main(){
	mystring str("hello");
	cout<<str.data()<<endl;
	mystring str2 = str;
	cout<<str2.data()<<endl;
	// mystring str3(str);
	// str3 = str;
	// cout<<str3.data()<<endl;
	return 0;
} */




/* class Point{
public:
	Point(int x_tmp=0,int y_tmp=0):
	x(x_tmp),y(y_tmp)
	{
		cout<<"构造点"<<x<<y<<endl;
	}
	~Point(){
		cout<<"point delet"<<endl;
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
	~Line(){
		cout<<"line deledete"<<endl;
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

	cout<<p2.getx()<<endl;
	cout<<l1.len()<<endl;
	return 0;
} */

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
