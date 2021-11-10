#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

inline int read(){
	int ret=0,f=1;char ch=getchar();
	while (ch<'0'||ch>'9') {if (ch=='-') f=-1;ch=getchar();}
	while (ch>='0'&&ch<='9') ret=ret*10+ch-'0',ch=getchar();
	return ret*f;
}

#define int long long

const int maxn=100005;

int t;
int n,minx,maxx;

signed main(){
	t=read();
	while (t--){
		n=read(),minx=read(),maxx=read();
		int x1=1,x2=2;
		for (int i=1;i<=n;i++){
			int w=read(),d=read();
			x1=x1*w+d; x2=x2*w+d;
		}
		x1&=1,x2&=1;
		int num1=0,num2=0;
		if (minx&1) num1++,minx++;
		if (maxx&1) num1++,maxx--;
		num1+=(maxx-minx)/2; num2+=(maxx-minx)/2+1;
		printf("%lld %lld\n",(1-x1)*num1+(1-x2)*num2,x1*num1+x2*num2);
	}
	return 0;
}