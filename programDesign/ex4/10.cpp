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

int t;

signed main(){
	t=read();
	while (t--){
		int a=read(),b=read();
		int now=1,flg=false;
		for (;;){
			if (!flg){
				if (a-now < 0) break;
				a-=now;
			} else {
				if (b-now < 0) break;
				b-=now;
			}
			flg=!flg; now++;
		}
		printf((flg)?"Limak\n":"Bob\n");
	}
	return 0;
}