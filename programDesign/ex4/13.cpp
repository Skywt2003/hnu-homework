#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
#include<cmath>

using namespace std;

inline int read(){
	int ret=0,f=1;char ch=getchar();
	while (ch<'0'||ch>'9') {if (ch=='-') f=-1;ch=getchar();}
	while (ch>='0'&&ch<='9') ret=ret*10+ch-'0',ch=getchar();
	return ret*f;
}

#define int long long

int a,b,n;

signed main(){
	a=read(),b=read(); n=read();
	printf("%lld.",a/b);
	while (n--){
		a=a%b*10;
		printf("%lld",a/b);
	}
	printf("\n");
	return 0;
}