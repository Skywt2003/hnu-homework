#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
#include<vector>
#include<cmath>

using namespace std;

inline int read(){
	int ret=0,f=1;char ch=getchar();
	while (ch<'0'||ch>'9') {if (ch=='-') f=-1;ch=getchar();}
	while (ch>='0'&&ch<='9') ret=ret*10+ch-'0',ch=getchar();
	return ret*f;
}

// #define int long long

double r,s;

double sqr(double x){return x*x;}

signed main(){
	scanf("%lf%lf",&r,&s);
	double k=( (sqr(r) < sqr(s)) ? sqrt(sqr(sin(r))+sqr(sin(s))) : sin(r*s)/2.0 );
	printf("%.5lf\n",k);
	return 0;
}