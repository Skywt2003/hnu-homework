#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
#include<map>
#include<vector>

using namespace std;
#define int long long

inline int read(){
	int ret=0,f=1; char ch=getchar();
	while (ch<'0'||ch>'9') {if (ch=='-') f=-1;ch=getchar();}
	while (ch>='0'&&ch<='9') ret=ret*10+ch-'0',ch=getchar();
	return ret*f;
}

const int maxn=1e4+5;

int n,m;
bool a[maxn];

signed main(){
	memset(a,true,sizeof(a));
	n=read(),m=read();
	while (m--){
		int x=read(),y=read();
		for (int i=x;i<=y;i++) a[i]=false;
	}
	int ans=0;
	for (int i=0;i<=n;i++) ans+=a[i];
	printf("%lld\n",ans);
	return 0;
}