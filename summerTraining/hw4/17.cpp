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

const int maxn=1005;

int n;
int a[maxn][maxn],f[maxn][maxn];
int last[maxn][maxn];

signed main(){
	n=read();
	for (int i=1;i<=n;i++)
		for (int j=1;j<=i;j++)
			a[i][j]=read();
	for (int i=1;i<=n;i++)
		for (int j=1;j<=n;j++){
			if (f[i-1][j] > f[i-1][j-1]) last[i][j]=j,f[i][j]=f[i-1][j]+a[i][j];
			else last[i][j]=j-1,f[i][j]=f[i-1][j-1]+a[i][j];
		}
	int ans=1;
	for (int i=2;i<=n;i++) if (f[n][i] > f[n][ans]) ans=i;
	printf("%d\n",f[n][ans]);
	std::vector<int> vec; vec.clear();
	for (int i=n;i>=1;i--) vec.push_back(a[i][ans]),ans=last[i][ans];
	for (int i=(int)vec.size()-1;i>=0;i--) printf("%d ",vec[i]);
	printf("\n");
	return 0;
}