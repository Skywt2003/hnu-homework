#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
#include<cmath>

using namespace std;

inline int read(){
	int ret=0,f=1;char ch=getchar();
	while (ch<'0'||ch>'9') {if (ch=='-') f=-1;ch=getchar();}
	while (ch>='0'&&ch<='9') ret=ret*10+ch-'0',ch=getchar();
	return ret*f;
}

#define int long long

int n;
int pos=0;
int ans=0;

signed main(){
	n=read();
	while (n--){
		int x=read();
		if (x > pos) ans+=(x-pos)*6 + 5; else
		if (x < pos) ans+=(pos-x)*4 + 5;
		pos=x;
	}
	printf("%lld\n",ans);
	return 0;
}