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

int n;

const int maxn=100005;

int tot=0,lnk[maxn],nxt[maxn*2],to[maxn*2];
int fa[maxn],depth[maxn];
double prob[maxn];
bool is_leaf[maxn];

void add_edge(int x,int y){
	tot++, to[tot]=y;
	nxt[tot]=lnk[x]; lnk[x]=tot;
}

void build_tree(int x){
	is_leaf[x]=true;
	int sons=0;
	for (int i=lnk[x];i;i=nxt[i]) if (to[i]!=fa[x]){
		sons++;
		is_leaf[x]=false;
	}
	for (int i=lnk[x];i;i=nxt[i]) if (to[i]!=fa[x]){
		depth[to[i]]=depth[x]+1; fa[to[i]]=x;
		prob[to[i]]=prob[x]/sons;
		build_tree(to[i]);
	}
}

signed main(){
	n=read();
	for (int i=1;i<n;i++){
		int x=read(),y=read();
		add_edge(x,y); add_edge(y,x);
	}
	prob[1]=1.0;
	build_tree(1);

	double ans=0;
	for (int i=1;i<=n;i++) if (is_leaf[i]) ans+=prob[i]*depth[i]; 
	printf("%.7lf\n",ans);
	return 0;
}