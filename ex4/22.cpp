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

#define int long long

const int maxn=40;

int a,b;
int ans=0;

signed main(){
	a=read(),b=read();
	while (a || b) ans+=(a&1)!=(b&1),a>>=1,b>>=1;
	printf("%lld\n",ans);
	return 0;
}