#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
#include<cmath>
#include<map>

// using namespace std;
#define int long long

inline int read(){
	int ret=0,f=1; char ch=getchar();
	while (ch<'0'||ch>'9') {if (ch=='-') f=-1;ch=getchar();}
	while (ch>='0'&&ch<='9') ret=ret*10+ch-'0',ch=getchar();
	return ret*f;
}

const int maxn=1005;
const int INF=0x3f3f3f3f3f3f3f3f;

int n,w;
int a[maxn],sum[maxn];
int Max=0,Min=INF;

signed main(){
	n=read(),w=read();
	for (int i=1;i<=n;i++){
		a[i]=read(),sum[i]=sum[i-1]+a[i];
		Max=std::max(Max,sum[i]);
		Min=std::min(Min,sum[i]);
	}
	Max=std::max(0ll,Max);
	Min=std::min(0ll,Min);
	printf("%lld\n",std::max(0ll,(w-Max)-(-Min)+1));
}