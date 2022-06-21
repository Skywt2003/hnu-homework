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

#define int long long

const int maxn=1005;

int n;
int ans=0;

signed main(){
	n=read();
	for (int i=1;i<=n;i++){
		int s=read(),d=read();
		while (s <= ans) s+=d;
		ans=s;
	}
	printf("%lld\n",ans);
	return 0;
}