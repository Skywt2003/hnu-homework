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

const int maxn=1e6+5;

int n;
int a[maxn];
int ans=1,lst=1;

signed main(){
	n=read();
	for (int i=1;i<=n;i++) a[i]=read();
	for (int i=2;i<=n;i++){
		if (a[i]<=a[i-1]) lst=i;
		ans=max(ans,i-lst+1);
	}
	printf("%lld\n",ans);
	return 0;
}