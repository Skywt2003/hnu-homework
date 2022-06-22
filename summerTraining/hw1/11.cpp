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

#define sqr(_) ((_)*(_))

inline int read(){
	int ret=0,f=1; char ch=getchar();
	while (ch<'0'||ch>'9') {if (ch=='-') f=-1;ch=getchar();}
	while (ch>='0'&&ch<='9') ret=ret*10+ch-'0',ch=getchar();
	return ret*f;
}

const int maxn=10005;

int n;
int a[maxn];
double ave,ans;

signed main(){
	n=read();
	while (n){
		ave=0;
		for (int i=1;i<=n;i++) a[i]=read(),ave+=a[i];
		ave/=(1.0*n);
		ans=0;
		for (int i=1;i<=n;i++) ans+=sqr(ave-a[i]);
		ans/=(1.0*n);
		printf("%d\n",(int)(ans));
		n=read();
	}
}