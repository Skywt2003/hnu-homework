#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
#include<cmath>
#include<vector>

using namespace std;

inline int read(){
	int ret=0,f=1;char ch=getchar();
	while (ch<'0'||ch>'9') {if (ch=='-') f=-1;ch=getchar();}
	while (ch>='0'&&ch<='9') ret=ret*10+ch-'0',ch=getchar();
	return ret*f;
}

#define int long long

const int maxn=10005;

int n,ans=0;
bool vis[maxn];
int prime[maxn];

// 欧拉筛 yyds
inline void build_prime(){
	memset(vis,true,sizeof(vis));
    vis[1]=false;
    for (int i=2;i<=n;i++){
        if (vis[i]) prime[++prime[0]]=i;
        for (int j=1;j<=prime[0];j++){
            if (i*prime[j]>n) break;
            vis[i*prime[j]]=false;
            if (i%prime[j]==0) break;
        }
    }
}

signed main(){
	n=read();
	build_prime();
	int cnt=0;
	for (int i=1;i<=prime[0];i++){
		printf("%lld ",prime[i]); cnt++;
		if (cnt==10) printf("\n"),cnt=0;
	}
	if (!prime[0]) printf("null");
	printf("\n");
	return 0;
}

