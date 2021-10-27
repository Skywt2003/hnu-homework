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

const int maxn=105;

int n;
int a[maxn];

signed main(){
	n=read();
	for (int i=1;i<=n;i++) a[i]=read();
	int ans=0;
	for (int i=1;i<=n;i++){
		int now=0;
		for (int j=1;j<=n;j++) if (i!=j)
			for (int k=1;k<=n;k++) if (k!=i && k!=j)
				now+=(a[j]+a[k]==a[i]);
		ans+=now>0;
	}
	printf("%lld\n",ans);
	return 0;
}