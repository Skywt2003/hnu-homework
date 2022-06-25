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

const int maxn=1e5+5;

int n,m;

int tot=0,lnk[maxn],nxt[maxn*2],to[maxn*2];
bool have_cat[maxn];

void add_edge(int x,int y){
	tot++, to[tot]=y;
	nxt[tot]=lnk[x]; lnk[x]=tot;
}

int get_answer(int x,int cats,int fa){
	bool is_leaf=true;
	int ret=0;
	for (int i=lnk[x];i;i=nxt[i]) if (to[i]!=fa){
		is_leaf=false;
		if ((have_cat[x]?cats:0)+have_cat[to[i]] <= m)
			ret+=get_answer(to[i],(have_cat[x]?cats:0)+have_cat[to[i]],x);
	}
	if (is_leaf) return cats <= m;
	else return ret;
}

signed main(){
	n=read(),m=read();
	for (int i=1;i<=n;i++) have_cat[i]=read();
	for (int i=1;i<n;i++){
		int x=read(),y=read();
		add_edge(x,y);add_edge(y,x);
	}
	printf("%d\n",get_answer(1,have_cat[1],-1));
	return 0;
}