
#include "Date.h"

using namespace std;

const int year_days[13]={-1, 31,28,31,30,31,30,31,31,30,31,30,31};

// 判断是否闰年
bool isRun(int year){return ((year%400==0) || (year%4==0 && year%100!=0));}

// 返回 1900.1.1 至给定日期的天数
int getStartDays(Date aa){
	int ret=0;
	for (int i=1900;i<aa.y;i++) ret+=isRun(i)?366:365;
	for (int i=1;i<aa.m;i++){
		if (i==2) ret+=isRun(i)?29:28;
		else ret+=year_days[i];
	}
	return ret+aa.d;
}

// 返回两个日期之间的间隔天数
int Deviation(Date aa, Date bb){
	return getStartDays(bb) - getStartDays(aa);
}

int main(){
	
}