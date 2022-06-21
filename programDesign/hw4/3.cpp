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

int n,x,y;

signed main(){
	n=read(); x=read(),y=read();
	for (int i=0;i<=n;i++)
		for (int j=0;j<=n-i;j++){
			int k=n-i-j;
			if (i*6+j*6+k*8==x && i+j*2==y){
				printf("%lld %lld %lld\n",i,j,k);
				return 0;
			}
		}
	return 0;
}