#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

double x,y;

signed main(){
	scanf("%lf",&x);
	if (2.0<x && x<=10.0) printf("%.6lf\n",x*(x+2.0)); else
	if (-1.0<x && x<=2.0) printf("%.6lf\n",2.0*x); else
	printf("%.6lf\n",x-1.0);
	return 0;
}