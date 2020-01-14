#include "head.h"

// using namespace std;
// using namespace std;

STU::STU(string name_tmp,float score_tmp = 60.0)
:name(name_tmp),score(score_tmp){
	this->num++;
	cout<<"student added:"<<this->name<<" "<<this->num<<" "<<this->score<<endl; 
}
STU::~STU(){
	cout<<"student delete"<<endl;
}
/* void score_set(float score_tmp);
	void view_stu(); */
void STU::score_set(float score_tmp = 60.1){
	this->score = score_tmp;
	cout<<"this student "<<this->name<<"score is:"<<this->score<<endl;
}
void STU::view_stu(){
	cout<<"name:"<<this->name<<" num:"<<this->num<<"score:"<<this->score<<endl;
}