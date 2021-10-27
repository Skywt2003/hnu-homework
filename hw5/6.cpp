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

const int maxn=100+5;

int n;
int a[maxn];
int ans=-1;

signed main(){
	n=read();
	for (int i=1;i<=n;i++) a[i]=read();
	sort(a+1,a+1+n);
	for (int i=1;i<=n;i++){
		int j=i;
		while (j+1<=n && a[j+1]==a[i]) j++;
		if (j-i+1 >= (n+1)/2) ans=a[i];
		j=i;
	}
	if (ans!=-1) printf("%lld\n",ans);
	else printf("null\n");
	return 0;
}