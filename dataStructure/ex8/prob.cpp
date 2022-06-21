#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
#include<cmath>
#include<map>

using namespace std;

const int maxn=25;
int m,n;
int f[maxn][maxn];

signed main(){
	cin>>m>>n;
	f[1][1]=1;
	for (int i=1;i<=n;i++)
		for (int j=1;j<=m;j++){
			if (i==1 && j==1) continue;
			f[i][j]=f[i-1][j]+f[i][j-1];
		}
	printf("%d\n",f[n][m]);
	return 0;
}