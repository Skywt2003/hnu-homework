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

const int maxn=25;

int n;
int a[maxn],b[maxn];
int k[maxn];

void build_unfold(int i,int xup,int ktot){ // i,指数和系数
	if (i==n) {k[xup]+=ktot;return;}
	build_unfold(i+1,xup+1,ktot);
	build_unfold(i+1,xup,ktot*a[i+1]);
}

bool check(){
	for (int i=0;i<n;i++) if (b[i]!=k[i]) return false;
	return true;
}

signed main(){
	for (;;){
		n=read(); if (!n) break;
		for (int i=1;i<=n;i++) a[i]=read();
		for (int i=n-1;i>=0;i--) b[i]=read();
		memset(k,0,sizeof(k));
		build_unfold(0,0,1);
		printf(check()?"Y\n":"N\n");
	}
	return 0;
}