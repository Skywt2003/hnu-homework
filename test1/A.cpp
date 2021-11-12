#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

inline int read(){
	int ret=0,f=1;char ch=getchar();
	while (ch<'0'||ch>'9') {if (ch=='-') f=-1;ch=getchar();}
	while (ch>='0'&&ch<='9') ret=ret*10+ch-'0',ch=getchar();
	return ret*f;
}

#define int long long

const int maxn=1005;
const int INF=1LL<<60;

int n=0;
int a[maxn];
int ans=INF;

signed main(){
	n=read();
	for (int i=1;i<=n;i++) a[i]=read();
	for (int i=1;i<=n;i++)
		for (int j=i+1;j<=n;j++)
			ans=min(ans,abs(a[i]-a[j]));
	printf("%lld\n",ans);
	return 0;
}