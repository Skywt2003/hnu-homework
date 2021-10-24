#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
#include<cmath>
#include<vector>

using namespace std;

inline int read(){
	int ret=0,f=1;char ch=getchar();
	while (ch<'0'||ch>'9') {if (ch=='-') f=-1;ch=getchar();}
	while (ch>='0'&&ch<='9') ret=ret*10+ch-'0',ch=getchar();
	return ret*f;
}

// #define int long long
#define double long double

const double pi=3.1415926535;
double x;

signed main(){
	scanf("%Lf",&x);
	// double num1=x,flg=1.0;
	// double ans=0.0;

	// for (int i=1;;i++){
	// 	ans+=num1*flg;
	// 	if (num1 < 0.00000005) break;
	// 	num1=num1/(double)(i*2+1)*x/(double)(i*2) *x;
	// 	flg=-flg;
	// }
	printf("%.6Lf\n",sin(x));
	return 0;
}