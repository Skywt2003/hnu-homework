#include<cstdio>
#include<cstring>
#include<iostream>

using namespace std;

#define int long long

int n;
int a,b,c;

inline int read(){
	int ret=0,f=1;char ch=getchar();
	while (ch<'0'||ch>'9') {if (ch=='-') f=-1;ch=getchar();}
	while (ch>='0'&&ch<='9') ret=ret*10+ch-'0',ch=getchar();
	return ret*f;
}

signed main(){
	n=read();
	c=n/12; n%=12;
	b=c/3; c%=3;
	a=b/1760; b%=1760;
	if (a) printf("%lld mi ",a);
	if (b) printf("%lld yd ",b);
	if (c) printf("%lld ft ",c);
	if (n) printf("%lld in ",n);
	printf("\n");
	return 0;
}