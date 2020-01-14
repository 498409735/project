#ifndef _HEAD_H_
#define _HEAD_H_


#include <iostream>
#include <iomanip>
#include <string.h>
#include <math.h>
#include <unistd.h>

using namespace std;
class STU{
public:
	STU(string,float);
	~STU();
	void score_set(float score_tmp);
	void view_stu();
private:
	string name;
 unsigned int num;
	float score;
};
#endif