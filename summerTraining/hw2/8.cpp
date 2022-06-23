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

const int maxn=15;
const int step[4][2]={{-1,0},{0,1},{1,0},{0,-1}};

int n;
int a[maxn][maxn];

signed main(){
	n=read();
	int x=(n+1)/2,y=(n+1)/2,f=1;
	int now=1,cnt=0;
	a[x][y]=1;
	for (int i=2;i<=n*n;i++){
		x+=step[f][0],y+=step[f][1];
		a[x][y]=i;
		cnt++;
		if (cnt==now) f=(f+1)%4;
		if (cnt==2*now) now++,cnt=0,f=(f+1)%4;
	}
	for (int i=1;i<=n;i++){
		for (int j=1;j<=n;j++) printf("%d ",a[i][j]);
		printf("\n");
	}
	return 0;
}