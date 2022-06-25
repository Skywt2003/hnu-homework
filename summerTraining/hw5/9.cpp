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

const int maxn=105;

int n;
bool a[maxn];

signed main(){
	n=read();
	for (int i=1;i<=n;i++) a[i]=read();
	int ans=0;
	for (int i=1;i<=n;i++)
		for (int j=i;j<=n;j++){
			for (int k=i;k<=j;k++) a[k]=1-a[k];
			int now=0;
			for (int i=1;i<=n;i++) now+=a[i];
			ans=std::max(ans,now);
			for (int k=i;k<=j;k++) a[k]=1-a[k];
		}
	printf("%d\n",ans);
	return 0;
}