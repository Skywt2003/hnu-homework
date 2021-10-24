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

int n,m,ans=0;

signed main(){
	n=abs(read()); m=read();
	for (int i=m;i>=1 && n>0;i--)
		if (n >= i*2-1) ans+=n/(i*2-1),n%=(i*2-1);
	printf("%lld\n",ans);
	return 0;
}