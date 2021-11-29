#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>

using namespace std;

const int maxn=1005;

int t,n,m;
char s[maxn][maxn];
int row_sum[maxn],col_sum[maxn];

signed main(){
	scanf("%d",&t);
	while (t--){
		scanf("%d%d",&n,&m);
		for (int i=1;i<=n;i++) scanf("%s",s[i]+1);

		memset(row_sum,0,sizeof(int)*(n+1));
		memset(col_sum,0,sizeof(int)*(m+1));
		int cnt=0;
		for (int i=1;i<=n;i++)
			for (int j=1;j<=m;j++)
				if (s[i][j]=='*') row_sum[i]++,col_sum[j]++,cnt++;
		bool flg=false;
		for (int i=1;i<=n&&(!flg);i++)
			for (int j=1;j<=m&&(!flg);j++)
				if (row_sum[i]+col_sum[j]-(s[i][j]=='*') == cnt) flg=true;
		
		printf(flg?"YES\n":"NO\n");
	}
	return 0;
}