#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>

using namespace std;

inline int read(){
	int ret=0,f=1;char ch=getchar();
	while (ch<'0'||ch>'9') {if (ch=='-') f=-1;ch=getchar();}
	while (ch>='0'&&ch<='9') ret=ret*10+ch-'0',ch=getchar();
	return ret*f;
}

#define int long long

const int maxn=1005;

int n,k,r[maxn];
bool con[maxn][maxn];

signed main(){
	n=read();k=read();
	for (int i=1;i<=n;i++) r[i]=read();
	for (int i=1;i<=k;i++){
		int x=read(),y=read();
		con[x][y]=con[y][x]=true;
	}
	for (int i=1;i<=n;i++){
		int now=0;
		for (int j=1;j<=n;j++) if (i!=j && r[i]>r[j] && con[i][j]==false) now++;
		printf("%lld ",now);
	}
	printf("\n");
	return 0;
}