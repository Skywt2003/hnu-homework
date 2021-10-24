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

int n;

signed main(){
	n=read();
	int now=0,ans=0;
	for (int i=1;;i++)
		if (now+i <= n) ans+=i*i,now+=i;
		else {ans+=(n-now)*i;break;}
	printf("%lld\n",ans);
	return 0;
}