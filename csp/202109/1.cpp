#include<cstdio>
#include<cstring>
#include<iostream>

using namespace std;

inline int read(){
	int ret=0,f=1; char ch=getchar();
	while (ch<'0'||ch>'9') {if (ch=='-') f=-1;ch=getchar();}
	while (ch>='0'&&ch<='9') ret=ret*10+ch-'0',ch=getchar();
	return ret*f;
}

const int maxn=105;

int n,a[maxn];
int sum1=0,sum2=0;

signed main(){
	n=read();
	for (int i=1;i<=n;i++){
		a[i]=read(); sum1+=a[i];
		if (a[i]!=a[i-1]) sum2+=a[i];
	}
	printf("%d\n%d\n",sum1,sum2);
	return 0;
}