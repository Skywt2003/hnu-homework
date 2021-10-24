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

int n;

bool check_twelve(int x){
	int a[40]; a[0]=0;
	while (x) a[++a[0]]=x%10,x/=10;
	for (int i=1;i<a[0];i++) if (a[i]==2 && a[i+1]==1) return true;
	return false;
}

signed main(){
	n=read();
	for (int i=1;i<=n;i++) if (i%12==0 || check_twelve(i)) printf("%lld ",i);
	printf("\n");
	return 0;
}