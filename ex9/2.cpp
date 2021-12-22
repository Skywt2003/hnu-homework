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

const int maxn=105;

int n,m;
int cnt[maxn];
int awd[maxn];

signed main(){
	n=read(),m=read();
	for (int i=1;i<=m;i++){
		memset(cnt,0,sizeof(cnt));
		for (int j=1;j<=n;j++) cnt[j]=read();
		int maxx=-1,winner=-1;
		for (int j=1;j<=n;j++) if (cnt[j]>maxx) maxx=cnt[j],winner=j;
		awd[winner]++;
	}
	int ansx=-1,ans=-1;
	for (int i=1;i<=n;i++) if (awd[i]>ansx) ansx=awd[i],ans=i;
	printf("%d\n",ans);
	return 0;
}