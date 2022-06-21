#include<cstdio>
#include<cstring>
#include<iostream>

using namespace std;

signed main(){
	double x,a,b,c,d;
	scanf("%lf%lf%lf%lf%lf",&x,&a,&b,&c,&d);
	printf("%.7lf\n",a*x*x*x + b*x*x + c*x + d);
	return 0;
}