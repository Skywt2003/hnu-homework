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

const int maxn=10005,N=10000;
int n;
int a[maxn];
int cnt[maxn];

signed main(){
	n=read();
	while (n){
		memset(cnt,0,sizeof(cnt));
		for (int i=1;i<=n;i++) a[i]=read(),cnt[a[i]]++;
		int ans=0,ans_cnt=0;
		for (int i=1;i<=N;i++) if (cnt[i]>ans_cnt) ans_cnt=cnt[i],ans=i;
		printf("%d\n",ans);
		n=read();
	}
	return 0;
}