#include<cstdio>
#include<cstring>
#include<iostream>

using namespace std;

inline int read(){
	int ret=0,f=1;char ch=getchar();
	while (ch<'0'||ch>'9') {if (ch=='-') f=-1;ch=getchar();}
	while (ch>='0'&&ch<='9') ret=ret*10+ch-'0',ch=getchar();
	return ret*f;
}

const int maxn=105;
const int INF=1<<30;
int n,ans=INF;

signed main(){
	n=read();
	for (int i=1;i<=n;i++) ans=min(ans,read());
	printf("%d\n",ans);
	return 0;
}