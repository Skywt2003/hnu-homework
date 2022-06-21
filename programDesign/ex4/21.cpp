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

const int maxn=40;

int x,ans;
int hh,mm;

bool check_seven(int h,int m){
	if (h%10==7 || h/10==7) return true;
	if (m%10==7 || m/10==7) return true;
	return false;
}

signed main(){
	x=read(); hh=read(),mm=read();
	for (;;){
		if (check_seven(hh,mm)) break;
		mm-=x;
		while (mm<0) mm+=60,hh--;
		while (hh<0) hh+=24;
		ans++;
	}
	printf("%lld\n",ans);
	return 0;
}