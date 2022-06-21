#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>

using namespace std;

inline int read(){
	int ret=0,f=1;char ch=getchar();
	while (ch<'0'||ch>'9') {if (ch=='-') f=-1;ch=getchar();}
	while (ch>='0'&&ch<='9') ret=ret*10+ch-'0',ch=getchar();
	return ret*f;
}

#define int long long

const int maxn=1005;

int n,k,M,D;
int ans;

signed main(){
	n=read(),k=read(),M=read(),D=read();
	for (int i=1;i<=M;i++) if ((n/i-1)/k+1 <= D) ans=max(ans,((n/i-1)/k+1)*i);
	printf("%lld\n",ans);
	return 0;
}