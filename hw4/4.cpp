#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
#include<cmath>
#include<vector>

using namespace std;

inline int read(){
	int ret=0,f=1;char ch=getchar();
	while (ch<'0'||ch>'9') {if (ch=='-') f=-1;ch=getchar();}
	while (ch>='0'&&ch<='9') ret=ret*10+ch-'0',ch=getchar();
	return ret*f;
}

#define int long long

const int maxn=1005;

int n,a[maxn];
int ans=0;

signed main(){
	n=read();
	for (int i=1;i<=n;i++) a[i]=read();
	sort(a+1,a+1+n);

	for (int i=1;i<=n;i++){
		int j=i;
		while (j+1<=n && a[j+1]==a[i]) j++;
		if (i-1 == n-j){
			printf("%lld\n",a[i]);
			return 0;
		}
		i=j;
	}
	printf("-1\n");
	return 0;
}