// 可以优化到 nlogn 但是数据范围太小懒得写

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

const int maxn=5005;

int n;
int a[maxn];

signed main(){
	for (;;){
		n=read();
		if (!n) break;
		for (int i=1;i<=n;i++) a[i]=read();
		int ans=0;
		for (int i=1;i<n;i++)
			for (int j=i+1;j<=n;j++)
				ans += a[i] > a[j];
		printf("%d\n",ans);
	}
	return 0;
}