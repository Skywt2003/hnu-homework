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

int t,a,b,k;

signed main(){
	t=read();
	while (t--){
		a=read(),b=read(),k=read();
		printf("%lld\n",(a-b)*(k/2) + (k&1)*a);
	}
	return 0;
}