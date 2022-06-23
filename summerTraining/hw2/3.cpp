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

const int maxn=100005;
const int INF=0x3f3f3f3f;

int n,a[maxn];
int Max=0,Min=INF;

int abs(int x){
	return (x<0)?-x:x;
}

int get_dist(int x){
	return abs(abs(x-Max)-abs(x-Min));
}

signed main(){
	n=read();
	for (int i=1;i<=n;i++) a[i]=read(),Max=std::max(Max,a[i]),Min=std::min(Min,a[i]);
	int ans=1;
	for (int i=2;i<=n;i++)
		if (get_dist(a[i])<get_dist(a[ans]) || (get_dist(a[i])==get_dist(a[ans]) && a[i]<a[ans])) ans=i;

	printf("%d\n",a[ans]);
	return 0;
}