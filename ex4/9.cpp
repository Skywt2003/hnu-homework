#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
#include<cmath>

using namespace std;

inline int read(){
	int ret=0,f=1;char ch=getchar();
	while (ch<'0'||ch>'9') {if (ch=='-') f=-1;ch=getchar();}
	while (ch>='0'&&ch<='9') ret=ret*10+ch-'0',ch=getchar();
	return ret*f;
}

#define int long long

int t,n,k,ans=0;

signed main(){
	t=read();
	while (t--){
		ans=0;
		n=read(),k=read();
		while (n--){
			int ti=read(),di=read();
			if (ti <= k) {k-=ti;continue;}
			ti-=k,k=0; ans+=ti*di;
		}
		printf("%lld\n",ans);
	}
	return 0;
}