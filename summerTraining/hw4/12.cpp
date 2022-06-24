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

const int maxn=105;
int a[maxn][maxn];

signed main(){
	int n=read();
	int cnt=0;
	for (int i=2;i<=n+1;i++)
		for (int j=i-1;j>=1;j--)
			a[j][i-j]=++cnt;
	for (int i=1;i<=n;i++){
		for (int j=1;j<=n-i+1;j++)
			printf("%d ",a[i][j]);
		printf("\n");
	}
	return 0;
}