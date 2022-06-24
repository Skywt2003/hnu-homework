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

const int maxn=5005;

int n,a,b;
map<string,bool> vis;

string s;

bool f[maxn][maxn];
int g[maxn];

void build_substring(){
	for (int i=0;i<n;i++){
		string now=""; now+=s[i]; vis[now]=true;
		for (int j=i-1;j>=0;j--) now=s[j]+now,vis[now]=true;
		now="";
		for (int j=i+1;j<n;j++) now=now+s[j],f[i+1][j]=vis[now];
	}
}

signed main(){
	cin>>n>>a>>b;
	cin>>s;
	build_substring();
	memset(g,0x3f,sizeof(g));
	g[0]=a;
	for (int i=1;i<n;i++){
		g[i]=g[i-1]+a;
		for (int j=0;j<=i;j++) if (f[j][i]) g[i]=min(g[i],g[j-1]+b);
	}
	printf("%d\n",g[n-1]);
	return 0;
}