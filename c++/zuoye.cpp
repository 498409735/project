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
#include<iostream>
#include<string.h>
//#include<stdlib.h>
using namespace std;
   
class Mystring{
private:
    char* m_data;
public:
    Mystring(const char* str=0){
        if(str == NULL){
            m_data = new char[1];
        }else{
            m_data = new char[strlen(str)+1];
            strcpy(m_data,str);
        }
        cout << "构建了字符串:" << m_data << endl;
    }
    Mystring(const Mystring &rhs){
        if(this->m_data == rhs.m_data){
            return;
        }else{
            strcpy(this->m_data,rhs.m_data);
        }
        cout << "字符串被拷贝了" << endl;
    }
    void print(){
        cout << "当前字符串为:" << m_data << endl;
    }
    ~Mystring(){
        cout << this->m_data << "被析构了" << endl;
    }
    char* getstr(){
        return m_data;
    }

    Mystring operator+(const Mystring &other){
        cout << "+" << endl;
        Mystring m;
        delete []m.m_data;
        int len = strlen(this->m_data) + strlen(other.m_data) +1;
        m.m_data = new char[len];
        strcpy(m.m_data,this->m_data);
        strcat(m.m_data,other.m_data);
        return m;
    }
    Mystring &operator+=(const Mystring &other){
        cout << "+=" << endl;
        Mystring m;
        delete []m.m_data;
        int len = strlen(this->m_data) + strlen(other.m_data) +1;
        m.m_data = new char[len];
        strcpy(m.m_data,this->m_data);
        strcat(m.m_data,other.m_data);
        strcpy(this->m_data,m.m_data);
        return *this;
    }
    Mystring &operator=(const Mystring &other){
        cout << '=' << endl;
        strcpy(this->m_data,other.m_data);
        return *this;
    }
    char operator[](int i){
        cout << "[]" << endl;
        int len = strlen(this->m_data);
        if(i>=len){
            return 0;
        }else{
            return (char)(this->m_data[i]);
        }
    }
    bool operator>(const Mystring &other){
        if(strcmp(this->m_data,other.m_data)>0){
            return true;
        }else{
            return false;
        }
    }
    bool operator<(const Mystring &other){
        if(strcmp(this->m_data,other.m_data)<0){
            return true;
        }else{
            return false;
        }
   
    }
    bool operator>=(const Mystring &other){
        if(strcmp(this->m_data,other.m_data)>=0){
            return true;
        }else{
            return false;
        }
   
    }
    bool operator<=(const Mystring &other){
        if(strcmp(this->m_data,other.m_data)<=0){
            return true;
        }else{
            return false;
        }
    }
    bool operator==(const Mystring &other){
        if(strcmp(this->m_data,other.m_data)==0){
            return true;
        }else{
            return false;
        }
    }   
};

int main(){
    Mystring m1("hello"),m2("world");
    Mystring m3;
    m3 = m1 + m2;
    cout << "m1+m2 = " << m3.getstr() << endl;
    m1 += m2;
    cout << "m1+=m2 = " << m1.getstr() << endl;
    m1 = m2;
    cout << "m1=m2 = " << m1.getstr() << endl;
    m1[3];
    cout << "m1[3] = " << m1[3] << endl;
    if(m1.operator>(m2)){
        cout << "m1>m2" << endl;
    }else{
        cout << "m1<m2" << endl;
    }
    if(m3.operator<(m2)){
        cout << "m3<m2" << endl;
    }else{
        cout << "m1>m2" << endl;
    }
    if(m1.operator>=(m2)){
        cout << "m1>=m2" << endl;
    }else{
        cout << "m1<m2" << endl;
    }
    if(m1.operator<=(m2)){
        cout << "m1<=m2" << endl;
    }else{
        cout << "m1>m2" << endl;
    }
    if(m1.operator==(m2)){
        cout << "m1==m2" << endl;
    }else{
        cout << "m1!=m2" << endl;
    }
    return 0;
}
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

/* class Employee{
public:
    Employee( int num, string name):num(num){
		this->name = name;
		cout<<"构造函数"<<endl;
	}
    static int  cunt(){
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
int Employee::allnum = 0;
int main()
{
	string tmp ="zhangsan";
	int a =2020;
    Employee pes1(a,tmp);
    
    return 0;
} */
