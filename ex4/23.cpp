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

int t;
int yyyy,mm,dd;

bool is_run(int x){
	if ((x%4==0 && x%100!=0) || x%400==0) return true;
	return false;
}

bool is_smaller(int m,int d){
	return (m<2 || (m==2 && d<29));
}

signed main(){
	t=read();
	while (t--){
		yyyy=read(),mm=read(),dd=read();
		int delta=0;
		for (;;){
			yyyy++;
			delta=(delta + ((is_run(yyyy-(is_smaller(mm,dd)))?366:365)))%7;
			if (mm==2 && dd==29 && (!is_run(yyyy))) continue;
			if (!delta) {printf("%lld\n",yyyy);break;}
		}
	}
	return 0;
}