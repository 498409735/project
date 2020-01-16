/* **************************************************************************
		三种排序
 */
 void print_data(int* arr,int len){
	int i = 0;
	for(i=0;i<len;i++){
		printf("%d ",arr[i]);
	}
	printf("\n");
}

void bubble_sort(int* arr,int len){
	int i = 0,j = 0;
	int temp = 0;
	for(i=0;i<len-1;i++){
		for(j=0;j<len-1;j++){
			if(arr[j] > arr[j+1]){
				temp = arr[j];
				arr[j] = arr[j+1];
				arr[j+1] = temp;
			}
		}
	}
}

void select_sort(int* arr,int len){
	int i = 0,j = 0;
	int min = 0;
	int temp = 0;
	for(i=0;i<len-1;i++){
		min = i;
		for(j=i;j<len;j++){
			if(arr[j] < arr[min]){
				min = j;
			}
		}
		temp = arr[min];
		arr[min] = arr[i];
		arr[i] = temp;
	}
}
/*
	6 1 2 7 9 3 4 5 10 8
*/

void quick_sort(int* arr,int left,int right){
	if(left>=right){return ;}
	int l = left;
	int r = right;
	int key = arr[left];
	int temp = 0;
	while(l<r){
		while(l<r){
			if(arr[r]<key){
				break;
			}
			r--;
		}
		while(l<r){
			if(arr[l]>key){
				break;
			}
			l++;
		}
		temp = arr[l];
		arr[l] = arr[r];
		arr[r] = temp;
	}
	temp = arr[left];
	arr[left] = arr[l];
	arr[l] = temp;
	quick_sort(arr,left,l-1);
	quick_sort(arr,l+1,right);
}

int compare(const void* a,const void* b){
	return *(int*)a - *(int*)b;
}

int main(){
	srand(time(0));
	int len = 10;
	int arr[len];
	int i = 0;
	for(i=0;i<len;i++){
		arr[i] = rand()%100;
	}
	print_data(arr,len);
	printf("\n");
	//bubble_sort(arr,len);
	//select_sort(arr,len);
	//quick_sort(arr,0,len-1);
	qsort(arr,10,4,compare);
	print_data(arr,len);
	return 0;
}

/*
	使用二维数组，输出一个10层的杨辉三角形
	输出格式为:printf("%6d",data)
*/

#include<stdio.h>

int main(){
	int arr[10][10] = {0};
	int i = 0,j = 0;

	for(i=0;i<10;i++){
		for(j=0;j<10;j++){
			if(j==0 || j==i){
				arr[i][j] = 1;
			}
		}
	}

	for(i=0;i<10;i++){
		for(j=0;j<10;j++){
			if(i>1 && j<i){
				arr[i][j] = arr[i-1][j] + arr[i-1][j-1];
			}
		}
	}

	for(i=0;i<10;i++){
		for(j=0;j<10-i;j++){
			printf("   ");
		}
		for(j=0;j<i+1;j++){
			printf("%6d",arr[i][j]);
		}
		printf("\n");
	}
	return 0;
}
/* ********************************************************************
		二维数组对角线和
 */
 void print_arr(int(* arr)[3]){
	int i = 0,j = 0;
	for(i=0;i<5;i++){
		for(j=0;j<3;j++){
			printf("%d ",arr[i][j]);
		}
		printf("\n");
	}
}

int main(){
	int arr[5][5] = {
						{1 ,2 ,3 ,4 ,1 },
						{4 ,2 ,6 ,2 ,8 },
						{7 ,8 ,3 ,10,11},
						{10,4,12,4,14},
						{5,14,15,16,5},
					};
	printf("%d\n",arr[0][2]);//9
	printf("%d\n",arr[4][2]);
	printf("%d\n",arr[0][14]);
	//print_arr(arr);
	int i = 0, j = 0;
	int res = 0;
	for(i=0;i<5;i++){
		for(j=0;j<5;j++){
			if(i==j||i+j==4){
				res = res + arr[i][j];
			}
		}
	}
	printf("res = %d\n",res);
	res = 0;
	for(i=0;i<5;i++){
		for(j=0;j<5;j++){
			if(i==0||i==4||j==0||j==4){
				res = res + arr[i][j];
			}
		}
	}
	printf("res = %d\n",res);
	return 0;
}
/*
	从键盘上输入任意整型数据，将他翻转后输出

	从键盘输入一个数，判断他是否为回文数
	12321,123321,32123,321123都是回文数，123456不是回文数
*/

int main(){
	int num = 0;
	scanf("%d",&num);
	while(getchar()!=10);
	//12345
	int i = 0;
	int res = 0;
	//0*10+5
	//5*10+4
	//54*10+3
	//543*10+2
	//5432*10+1
	for(i=num;i>0;i/=10){
		res = res*10 + i%10;
	}
	printf("res = %d\n",res);
	return 0;
}
/*
	1-1/3+1/5-1/7+1/9-....-1/99+1/101
*/

/*
	将1-1/3+1/5-1/7...这么一组减法操作看成一组，然后所有组加起来

	申请一个循环变量，他的值为1，他会随着循环的进行，在1和-1之间反复变换
*/

#include<stdio.h>

int main(){
	int num = 0;
	scanf("%d",&num);
	while(getchar()!=10);
	int i = 0;
	int j = 1;
	double res = 0;
	for(i=1;i<=num;i+=2){
		res = res + 1.0/i*j;
		j=-j;
	}
	printf("res = %g\n",res);
	return 0;
}
	/*
	键盘输入一个十进制数，将他转换成二进制输出
*/

int main(){
	int num = 0;
	scanf("%d",&num);
	while(getchar()!=10);
	//10
	int i = 0;
	//10%2=	0
	//5%2=	1
	//2%2=	0
	//1%2=	1
	int j = 0;
	int res = 0;
	int temp = 1;
	//0+1*0
	//1+10*1
	//10+100*0
	//10+1000*1
	for(i=num;i>0;i/=2){
		res = res + temp * (i%2);
		temp = temp*10;
	}
	printf("res = %d\n",res);
	return 0;
}
/*
	从键盘输入2个数，使用循环求出这两个数的最大公约数和最小公倍数
*/
#include<stdio.h>

int main(){
	int a = 0,b = 0;
	scanf("%d %d",&a,&b);
	while(getchar()!=10);
	int smaller = (a<b)?a:b;
	int i = 0;
/*
	for(i=smaller;1;i--){
		if(a%i==0 && b%i==0){break;}
	}
*/
	for(i=smaller;a%i!=0 || b%i!=0;i--);
	printf("%d 和 %d 的最大公约数为 :%d\n",a,b,i);

	int bigger = (a>b)?a:b;
/*
	for(i=bigger;1;i++){
		if(i%a==0 && i%b==0){break;}
	}
*/
	for(i=bigger;i%a!=0 || i%b!=0;i++);
	printf("%d 和 %d 的最小公倍数为 :%d\n",a,b,i);
	return 0;
}
/*
	斐波那契数列：前两项是1，从第3项开始，每一项都是前两项之和
*/
/*
			1	1	2	3	5	8	13
第一次循环	n1	n2	n3
第二次循环		n1	n2	n3
第三次循环			n1	n2	n3
*/
int main(){
	int i = 0;
	int n = 0;
	int n1 = 1,n2 = 1;
	int n3 = 1;
	scanf("%d",&n);
	while(getchar()!=10);
	for(i=3;i<=n;i++){
		n3 = n1 + n2;
		n1 = n2;
		n2 = n3;
	}
	printf("第%d项的值为%d\n",n,n3);
	return 0;
}
int main(){
/*
	int i = 0,j = 0;
	for(i=0;i<5;i++){
		for(j=0;j<5-i;j++){
			printf(" ");
		}
		for(j=0;j<i+1;j++){
			printf("* ");
		}
		printf("\n");
	}
	由于，想要输出不同层数的三角形的时候，奇迹上，整段代码中，只有5这个数字发生改变，所以，我们考虑将这段代码封装成一个功能模块，然后为该功能模块提供一个修改数据的接口，这个接口就是专门用来修改三角形层数。
	这样一来，无论我想要打印n次m层的三角形，只需要调用n次该功能模块，并且每一次调用的时候，准确的从接口处确定层数m的值即可
*/
	int n = 5;//n依靠参数导入
	int i = 0;
	int res = 0;
	for(int i=0;i<n;i++){
		res = res + i;
	}
	return 0;
}
/*
	我们把，这个封装了一整段代码，并且实现某个功能的模块，就称为函数，为函数提供数据导入功能的接口，我们称为函数的参数
	注意：当函数封装成功之后，该函数模块就成了一个暗箱，内部的所有数据，外部不能直接修改，也不能直接获取。想要修改函数内部的数据，只能通过名为参数的接口。想要获得内部的数据，只能通过名为返回值的接口
*/
/*
	以上说到的2点就是函数3要素中的2个要素
		① 函数名
		② 函数参数(外部用来修改内部数据的接口)
		③ 函数返回值(内向外部输出输出的接口)
	函数与变量一样，在使用之前必须声明，但是函数和变量不一样的地方在于，函数在使用之前，必须定义
	如何声明及定义一个函数：
		声明部分：函数返回值类型 + 函数名(函数具体需要的参数，也就是函数的参数列表),注意，参数列表必须是声明变量的形式
		定义部分：在函数声明部分之后加上{},{}内的就是函数的定义部分
*/
/*
	调用一个函数，总是出于以下3种目的
		① 仅仅实现某一个功能(例如，在函数中打印一个n层三角形)
		② 仅仅计算某种运算的结果(使用函数计算1～n之和)
		③ 同时实现功能和计算结果:例如printf
*/
/*
	函数返回值的应用：
		函数的返回值可以包含多种多样的含义，并不一定是某种运算的运算结果，也可以是某种功能在运行当中，判断是否运行成功的标识。
		比方说，有如下函数，寻找6到10之内，是否拥有质数。这个函数的它就属于第③调用目的，功能为判断是否有质数，结果寻找到的质数个数。
		再比方说，有如下函数，判断某一个数是否为质数。这个函数也属于第三种调用目的，功能为判断该数是否是质数，结果就应该是判断的结果，不是质数，函数返回值为0。
*/
/*
	关于函数参数的应用
	由于函数的参数导入的过程是一个赋值的过程，所以就会产生一个比较麻烦的结果，在函数内部，改变参数的值，函数外部的参数不会改变
	我们把函数内部的参数称为函数的形参，函数外部的参数称为函数的实参，参数的传递过程(导入过程)，本质上是将实参的值赋值给形参，所以形参和实参是两个完全不同的个体数据，只不过数值是一样的。所以当形参发生改变的时候，实参不会有任何的变化
	很多时候，我们的目的就是将实参传入函数，通过某些特定规则改变实参的值，但是实参进入函数的方式只能是通过形参，然后形参的改变又不会影响到实参的值，为了解决这个问题，我们有以下两种解决方案。
		① 当形参发生改变之后，函数结束之前，我们将形参返回，并在外部使用实参去接受函数返回的形参
			但是，这种方式存在明显的缺点，就是当改变的形参不止1个的时候，但是返回值又只能返回1个数据，所以导致不能保证2组形参和实参的同步性。所以这个时候，我们就会采用第二中方式，来确保形参和实参的同步性
		② 将实参的地址传递给形参，所以形参本质上就是实参的地址，对形参取值，本质上就是对实参的地址取值，取出来的自然就是实参。

	函数使用过程当中，一共有3个难点。
		① 函数返回值的设计，也就是需要确定函数返回值的意义
		② 保证实参与形参的同步性
		③ 当有多重函数嵌套调用的时候，一定要认清当前函数到底完成的是什么功能，以及当前函数的参数到底是从何处传递进来的并且当前函数的返回值到底要传递到何处
*/
/*
	在函数传参的过程中，我们人为规定，如果传入的参数，在函数内部会发生改变，那么就必须传指针。如果传入的参数在函数内部不会发生改变，就必须传普通数据
*/
/*
	编写一个注册登录系统：
		首先明确一件事情：所有注册成功的账号和密码都会分别保存在一个long long int 的nameDB 和 pswdDB当中，如何保存呢？这里限制输入的账号和密码只能是3位整型数
		举例说明，当输入的账号 name = 123的时候，那么就应该将name保存到nameDB中的第0个位置上，保存形式就是nameDB = 1230,当第二次注册账号成功后,比方说name = 456,那么就应该将 name = 456 保存到nameDB中的第1个位置上去，也就是说nameDB = 12304561
		密码保存方式同理

		基本要求：
			注册的时候，当用户输入想要注册的账号之后，首先判断nameDB中是否已经存在该账号，如果存在则注册失败，不存在则注册成功
			登录的时候，当用户输入想要登录的账号之后，首先判断nameDB是否存在该账户，如果存在，则继续输入密码，不存在则登录失败
			密码还需要判断是否正确

		进阶要求：登录时，账号允许无限次错误。密码如果输入错误3次以上，再次输入密码的时候要求输入验证码，验证码为随机生成的4位整型数，错误6次以上直接退出程序(验证码错误也算作密码错误)
 		分析：①注册函数②登录函数③查找账号函数
*/
#include<stdio.h>


typedef long long int lli;

int find_data(int name,lli nameDB){
	int i = 0;
	for(i=nameDB;i>0;i/=10000){//12304561
		if(name == i%10000/10){
			return i%10;
		}
	}
	return -1;
}

void regist(lli* nameDB,lli* pswdDB,int* len){
	int name = 0,pswd = 0;
	printf("请输入账号:");
	scanf("%d",&name);
	while(getchar()!=10);
	//查看name在nameDB中是否存在
	int res = find_data(name,*nameDB);
	if(res >= 0){
		printf("该账号已存在\n");
		return ;
	}
	*nameDB = *nameDB*10000 + name*10 + *len;
	printf("请输入密码:");
	scanf("%d",&pswd);
	while(getchar()!=10);
	*pswdDB = *pswdDB*10000 + pswd*10 + *len;
	(*len)++;
}

int login(lli nameDB,lli pswdDB){
	int name = 0,pswd = 0;
	printf("请输入账号:");
	scanf("%d",&name);
	while(getchar()!=10);
	int res = find_data(name,nameDB);
	if(res == -1){
		printf("该账号不存在\n");
		return 0;
	}
	printf("请输入密码:");
	scanf("%d",&pswd);
	while(getchar()!=10);
	pswd = pswd*10 + res;
	int i = 0;
	for(i=pswdDB;i>0;i/=10000){
		if(pswd == i%10000){
			return 1;
		}
	}
	
	return 0;
}

int main(){
	lli nameDB = 0;
	lli pswdDB = 0;
	int len = 0;
	int ch = 0;
	int res = 0;
	while(1){
		printf("1:注册\n");
		printf("2:登录\n");
		printf("3:查看数据库\n");
		printf("请选择");
		scanf("%d",&ch);
		while(getchar()!=10);
		switch(ch){
			case 1:
				regist(&nameDB,&pswdDB,&len);
				break;
			case 2:
				res = login(nameDB,pswdDB);
				if(res == 1){
					printf("登录成功\n");
				}
				break;
			case 3:
				printf("nameDB = %lld\n",nameDB);
				printf("pswdDB = %lld\n",pswdDB);
				break;
			default:
				break;
		}
	}
	return 0;
}

/* ********************************************************************
        多个参数传入
********************************** */
 #include<stdio.h>
/*
	va_list 是一个指针变量类型，他相当于char*，因为他的模块大小是1个字节，但是是否为char*不清楚
*/

void func(int num,...){
	va_list p;
	va_start(p,num);//这个函数会将p指向可变参数的第一个参数,也就是固定参数num的下一个参数
	printf("%d\n",va_arg(p,int));//这个函数会将p当前指向参数，以基础类型为int类型取值,也就是说会准确的读取int数据所占据的4个字节内存并取值。然后再将p指向下一个可变参的地址，最后将从地址上取出来的值，返回给va_arg表达式
	printf("%d\n",va_arg(p,int));
	printf("%d\n",va_arg(p,int));
	printf("%d\n",va_arg(p,int));
	va_end(p);
}

int func(int num,...){
	va_list p;
	va_start(p,num);
	int i = 0;
	int res = 0;
	for(i=0;i<num;i++){
		res = res + va_arg(p,int);
	}
	va_end(p);
	return res ;
}
int* func(int* b){
	int a = 5;//0x21
	int* pa = &a;
	//pa = b;
	return pa;//return &a;
}
/*
	无论是返回pa也好，还是返回&a也好，都是返回一个局部变量地址，都属于非法操作。所以，无论如何神操作，都不允许返回一个栈空间局部变量的地址
*/
void insert(int* count){
	(*count)++;
}

void Remove(int* count){
	(*count)--;
}

void _insert(){
	static int count = 0;
	count++;
	printf("insert:%d\n",count);
}

void _Remove(){
	static int count = 0;
	count--;
	printf("remove:%d\n",count);
}

int main(){
	int count = 0;
/*	insert(&count);
	insert(&count);
	insert(&count);
	insert(&count);
	insert(&count);
	Remove(&count);
	Remove(&count);*/
	_insert();
	_insert();
	_insert();
	_Remove();
	_Remove();
	printf("容器中还有%d个数据\n",count);
	return 0;
}
int main(){
	int b = 5;
	int* pa = func(&b);
	printf("%d\n",*pa);
	return 0;
}
/*
	内存的概念：
		由于内存是由高低电平来表示二进制中的1和0以达到运算中告诉存储的目的。所以，内存最大的优点，运算速度快。最大的缺点就是一旦断电，则所有数据全都丢失。
		这个优缺点是相对于硬盘而言的：硬盘就是反过来，访问速度慢，但是断电数据依旧存在。
	
	linux系统中的内存大致可以分为以下几类：
		① 栈内存:
			1:先进后出
			2:自动申请自动释放
				所有在栈空间上产生的变量，都会自动在栈空间上申请一片内存空间。我们平时所说的声明变量，都是在栈空间上申请的空间。一旦该变量生命周期结束，该变量在栈空间上所申请的空间就会被系统自动回收。也就是说该变量所属的空间不再归用户所有。
			用户对于所有不被自己所拥有的地址，都会将他们称为野指针。
			所有针对野指针的修改/访问，一旦运行，就会段错误
			生命周期：通常情况下，一个变量的生命周期默认与作用域同步。
		② 静态存储区:
			独立于栈空间的另外一段空间，他的特点就是，当程序开始之前，静态存储区就已经存在，当程序结束之后，静态存储区才会消失
			所以，当一个数据存放到静态存储区之后，这个数据就可以在整个程序运行过程中，一直存在，无论变量名还是地址，都可以有效的访问到该数据(注意，如果通过变量名访问一个静态变量，依旧需要注意作用域)
			当使用变量名访问静态变量的时候：如果这个静态变量实在某一个特定的作用域中声明的话，虽然他的生命周期在整个程序中永久存在，但是他的作用域却被限定在了声明的作用域中，所以想要全局访问它的话的，只能通过指针
			如果一定要通过变量名的方式，全局访问一个静态变量的话，我们应该将这个静态变量声明在所有的{}以上，我们把这样的一个静态变量称为全局变量
			声明全局变量，不用加任何关键字，就会默认在静态存储区申请空间
			如果想在一个作用域内，声明静态变量的话，需要在声明的前面加上关键字static。
			static的作用：延长生命周期，限制作用域
		③ 堆内存
		④ 常量存储区:存放所有常量的地方
*/