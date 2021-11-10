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

int t;
int L,v,l,r;


signed main(){
	t=read();
	while (t--){
		L=read(),v=read(),l=read(),r=read();
		int ans=0;
		for (int i=v;i<=L;i+=v) if (i<l||i>r) ans++;
		printf("%lld\n",ans);
	}
	return 0;
}