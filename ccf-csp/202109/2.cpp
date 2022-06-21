#include<cstdio>
#include<cstring>
#include<iostream>

using namespace std;

inline int read(){
	int ret=0,f=1; char ch=getchar();
	while (ch<'0'||ch>'9') {if (ch=='-') f=-1;ch=getchar();}
	while (ch>='0'&&ch<='9') ret=ret*10+ch-'0',ch=getchar();
	return ret*f;
}

const int maxn=5e5+5,maxx=1e4+5,X=1e4;;

int n;
int a[maxn];

int delta[maxx];
int ans=0;

signed main(){
	n=read();
	for (int i=1;i<=n;i++) a[i]=read();

	for (int i=1;i<=n;i++){
		int l=i,r=i;
		while (r+1<=n && a[r+1]==a[i]) r++;
		if (a[i] && a[l-1]<a[l] && a[r]>a[r+1]) delta[a[i]]--; else
		if (a[i] && a[l-1]>a[l] && a[r]<a[r+1]) delta[a[i]]++;
		i=r;
	}

	int last_zero = 0;
	for (int i=1;i<=n+1;i++) if (a[i]==0){
		if (last_zero != i-1) ans++;
		last_zero=i;
	}

	int now=ans;
	for (int i=0;i<=X;i++){
		now+=delta[i];
		ans=max(ans,now);
	}

	printf("%d\n",ans);
	return 0;
}