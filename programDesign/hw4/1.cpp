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

int days[13]={-1,31,28,31,30,31,30,31,31,30,31,30,31};
int w;

signed main(){
	w=read()-1;
	for (int i=1;i<=12;i++)
		for (int j=1;j<=days[i];j++){
			w=w%7+1;
			if (j==13 && w==5) printf("%lld ",i);
		}
	printf("\n");
	return 0;
}