#include<cstdio>
#include<cstring>
#include<iostream>

using namespace std;

signed main(){
	double a,b;
	scanf("%lf%lf",&a,&b);
	printf("%.2lf\n",a*b/(a+b));
	return 0;
}