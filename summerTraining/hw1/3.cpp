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

const int maxn=1e5+5;
int n;
int yleft=0,yright=0;

signed main(){
	n=read();
	for (int i=1;i<=n;i++){
		int x=read(),y=read();
		if (x<0) yleft++; else yright++;
	}
	printf((yleft<=1 || yright<=1)?"Yes\n":"No\n");
	return 0;
}