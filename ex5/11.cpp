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

const int maxn=100005;
const int INF=1LL<<30;
const int BASE=5000;

int n,d;
int a[maxn];
bool vis[maxn];
int ans=0;

signed main(){
	n=read(),d=read();
	for (int i=1;i<=n;i++) a[i]=read(),vis[a[i]+BASE]=true;
	for (int i=a[1]-d;i<=a[n]+d;i++) if (!vis[i+BASE]){
		int now=INF;
		for (int j=1;j<=n;j++) now=min(now,abs(a[j]-i));
		ans+=now==d;
	}
	printf("%lld\n",ans);
	return 0;
}