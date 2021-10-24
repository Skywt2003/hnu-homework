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

int n,u,d;

signed main(){
	for (;;){
		n=read(),u=read(),d=read();
		if (!n) return 0;

		int ans=0;
		for (;;){
			if (n <= u) {printf("%d\n",++ans);break;}
			n-=u-d; ans+=2;
		}
	}
	return 0;
}