#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
#include<cmath>
#include<map>

// using namespace std;
// #define int long long

inline int read(){
	int ret=0,f=1; char ch=getchar();
	while (ch<'0'||ch>'9') {if (ch=='-') f=-1;ch=getchar();}
	while (ch>='0'&&ch<='9') ret=ret*10+ch-'0',ch=getchar();
	return ret*f;
}

const int maxn=2e5+5;

int t;
int n,a[maxn],f[maxn];

signed main(){
	t=read();
	while (t--){
		n=read();
		for (int i=1;i<=n;i++) a[i]=read();
		int ans=0;
		for (int i=n;i>=1;i--)
			f[i]=a[i] + ((i+a[i]<=n)?f[i+a[i]]:0),
			ans=std::max(ans,f[i]);
		printf("%d\n",ans);
	}
	return 0;
}