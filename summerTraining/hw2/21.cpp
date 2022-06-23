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

const int maxn=1e7+5;

int n,k;
int s[maxn],v[maxn];
bool vis[maxn];

signed main(){
	n=read(),k=read();
	for (int i=1;i<=n;i++) s[i]=read();
	for (int i=1;i<=n;i++) v[i]=read();
	for (int i=1;i<=n;i++) if (i!=k) v[i]-=v[k],s[i]-=s[k];
	v[k]=s[k]=0; vis[k]=true;

	int Max=-1,Min=-1;
	for (int i=1;i<=n;i++) if (i!=k){
		if ((s[i]>0 && v[i]<0) || (s[i]<0 && v[i]>0) || s[i]==0){
			vis[i]=true;
			if (Min==-1 || v[i]<v[Min]) Min=i;
			if (Max==-1 || v[i]>v[Max]) Max=i;
		}
	}
	if (v[Min]<0) for (int i=1;i<=n;i++) if (s[i]<0 && v[i]<=0 && v[i]>v[Min]) vis[i]=true;
	if (v[Max]>0) for (int i=1;i<=n;i++) if (s[i]>0 && v[i]>=0 && v[i]<v[Max]) vis[i]=true;
	int ans=0;
	for (int i=1;i<=n;i++) ans+=vis[i];
	printf("%d\n",ans);
	return 0;
}