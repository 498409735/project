/*************************************************************************
	> File Name: zuoye.cpp
	> Author: 
	> Mail: 
	> Created Time: 2020年01月10日 星期五 18时40分38秒
 ************************************************************************/

#include<iostream>
#include<string.h>
#include<stdlib.h>
#include<math.h>
#include<unistd.h>

using namespace std;

/*class Square{
public:
    Square(double a)
    :a(a)
    {
        cout << "构造函数..." << endl;
    }

    double area(){
        return pow(a,2);
    }

    void copy(Square s){
        this->a = s.a;    
    }
    ~Square(){
        cout << "析构函数..." << endl;
    }
private:
    double a;
};

int main()
{
    Square s1(3);
    Square s2(5);
    cout << "拷贝前的s1的面积："<< s1.area() << endl;
    
    s1.copy(s2);
    cout << "拷贝后的s1的面积："<< s1.area() << endl;
    return 0;
}*/

/*class String{
public:
    String(const char* str=NULL){
        if(str == NULL){
            _data = new char[1];
        }else{        
            _data = new char[strlen(str)+1];
            strcpy(this->_data,str);          
        }
        cout << "被构造.." << endl;
    }
    String(const String &rhs){
        this->_data = new char[strlen(rhs._data)+1];
        strcpy(this->_data,rhs._data);
        cout << "拷贝构造..."  << endl;
    }
    const char* data()const{
        return _data;
    }
    ~String(){
        delete _data;
        cout << "被析构..." << endl;
    }

private:
    char* _data;
};

int main()
{
    String s("hello");
    String s1(s);
    cout << s1.data() << endl;
    cout << s.data() << endl;
    return 0;
}*/

/*class Time{
public:
    Time(int hour,int minute,int second)
    :hour(hour),minute(minute),second(second){
        cout << "构造时间为：" << hour << ":" 
            << minute << ":" << second << endl; 
    }
    void count(){
        if(this->second < 60 && this->second > 0){
            this->second = this->second+1;
        }else{
            if(this->minute < 60){
                this->minute = this->minute+1;
                this->second = 0;
            }else{
                if(this->hour < 24){
                    this->hour = this->hour+1;
                    this->minute = 0;
                    this->second = 0;
                }else{
                    this->hour = 0;
                    this->minute = 0;
                    this->second = 0;
                }
            }
        }
    }
    void print(){        
        cout << "现在时间为：" << hour << ":" 
            << minute << ":" << second << endl; 
    }
    ~Time(){
        cout << "被析构..." << endl;
    }
private:
    int hour,minute,second;
};

int main()
{
    Time t1(19,18,25);
    while(1){
        sleep(1);
        t1.count();
        t1.print();
    }

    return 0;
}*/
int Employee::allnum = 0;
class Employee{
public:
    Employee( int num, string name):num(num){
		this->name = name;
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
}
