#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>

using namespace std;

const int maxn=1005;

int n,m,k,sx,sy,f;
string s;

/*
 * 3NW 0NE
 *  \ /
 *  / \
 * 2SW 1SE
 */
int get_num(string s){
	if (s=="NE") return 0; else
	if (s=="NW") return 3; else
	if (s=="SE") return 1; else
	if (s=="SW") return 2; else
	printf("ERROR!!!\n");
	return 0;
}

int a[maxn][maxn];
bool vis[maxn][maxn][4];

signed main(){
	scanf("%d%d%d",&n,&m,&k);
	for (int i=0;i<=n+1;i++) a[i][0]=a[i][m+1]=true;
	for (int i=0;i<=m+1;i++) a[0][i]=a[n+1][i]=true;
	for (int i=1;i<=k;i++){
		int x,y;
		scanf("%d%d",&x,&y);
		a[x][y]=true;
	}
	scanf("%d%d",&sx,&sy);
	cin>>s; f=get_num(s);

/*
 * 3   0
 *  \ /
 *  / \
 * 2   1
 */

	for(;;){
		vis[sx][sy][f]=true;
		if (f==0){
			if (a[sx-1][sy+1]){
				if (a[sx-1][sy] && !a[sx][sy+1]) sy++,f=1; else
				if (a[sx][sy+1] && !a[sx-1][sy]) sx--,f=3; else
				f=2;
			} else sx--,sy++;
		} else if (f==1){
			if (a[sx+1][sy+1]){
				if (a[sx+1][sy] && !a[sx][sy+1]) sy++,f=0; else
				if (a[sx][sy+1] && !a[sx+1][sy]) sx++,f=2; else
				f=3;
			} else sx++,sy++;
		} else if (f==2){
			if (a[sx+1][sy-1]){
				if (a[sx+1][sy] && !a[sx][sy-1]) sy--,f=3; else
				if (a[sx][sy-1] && !a[sx+1][sy]) sx++,f=1; else
				f=0;
			} else sx++,sy--;
		} else if (f==3){
			if (a[sx-1][sy-1]){
				if (a[sx-1][sy] && !a[sx][sy-1]) sy--,f=2; else
				if (a[sx][sy-1] && !a[sx-1][sy]) sx--,f=0; else
				f=1;
			} else sx--,sy--;
		}
		if (vis[sx][sy][f]) break;
	}
	int ans=0;
	for (int i=1;i<=n;i++)
		for (int j=1;j<=m;j++)
			ans+=vis[i][j][0]||vis[i][j][1]||vis[i][j][2]||vis[i][j][3];
	printf("%d\n",ans);
	return 0;
}