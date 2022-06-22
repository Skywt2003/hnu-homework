#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
#include<cmath>
#include<map>

using namespace std;
// #define int long long

inline int read(){
	int ret=0,f=1; char ch=getchar();
	while (ch<'0'||ch>'9') {if (ch=='-') f=-1;ch=getchar();}
	while (ch>='0'&&ch<='9') ret=ret*10+ch-'0',ch=getchar();
	return ret*f;
}

const int maxn=2005;
int n,m;
char a[maxn][maxn];
int cnt[maxn];

signed main(){
	n=read(),m=read();
	for (int i=1;i<=n;i++) scanf("%s",a[i]+1);
	for (int i=1;i<=n;i++)
		for (int j=1;j<=m;j++)
			if (a[i][j]=='1') cnt[j]++;
	for (int i=1;i<=n;i++){
		bool ans=true;
		for (int j=1;j<=m;j++) if ((a[i][j]=='1' && cnt[j]==1) || (a[i][j]=='0' && cnt[j]==0)) ans=false;
		if (ans){
			printf("YES\n");
			return 0;
		}
	}
	printf("NO\n");
	return 0;
}