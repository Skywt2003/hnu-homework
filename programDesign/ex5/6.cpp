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

int t,n,k;
int ans;

signed main(){
	t=read();
	while (t--){
		n=read();k=read();
		int ans=0,lst=0;
		for (int i=1;i<=k;i++){
			int now=read();
			ans=max(ans,(now-lst)/2+1); lst=now;
			if (i==1) ans=max(ans,now);
			if (i==k) ans=max(ans,n-now+1);
		}
		printf("%lld\n",ans);
	}
	return 0;
}