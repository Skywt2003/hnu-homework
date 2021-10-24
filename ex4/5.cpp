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

int n,m,pos=1;
bool flg=true;

signed main(){
	n=read(),m=read();
	if (n==1) {printf("1\n");return 0;}
	while (m--){
		int x=read()%(n*2-2);
		while (x--){
			if (flg) pos++; else pos--;
			if (pos==1 || pos==n) flg=!flg;
		}
	}
	printf("%lld\n",pos);
	return 0;
}