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

int x,y;

int fun(int num){
	if (num<10) return 0;
	int now=1;
	while (now*10<num) now*=10;
	return num%now;
}

signed main(){
	printf("%lld\n",fun(read()));
}