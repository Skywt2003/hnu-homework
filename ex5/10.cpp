#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>

using namespace std;

inline int read(){
	int ret=0,f=1;char ch=getchar();
	while (ch<'0'||ch>'9') {if (ch=='-') f=-1;ch=getchar();}
	while (ch>='0'&&ch<='9') ret=ret*10+ch-'0',ch=getchar();
	return ret*f;
}

#define int long long

const int maxn=1005;

int n,s;
int a[maxn];

signed main(){
	n=read(),s=read();
	// printf("! %lld %lld\n",n,s);
	for (int i=1;i<=n;i++){
		int x=read(),y=read();
		// printf("! %lld %lld\n",x,y);
		a[i]=x*60+y;
	}
	a[0]=-s-1;
	for (int i=0;i<n;i++) if (a[i+1]-a[i]-1 >= s*2+1){
		printf("%lld %lld\n",(a[i]+s+1)/60,(a[i]+s+1)%60);
		return 0;
	}
	printf("%lld %lld\n",(a[n]+s+1)/60,(a[n]+s+1)%60);
	return 0;
}

/* 
Case#1:
! 20 59
! 1 0
! 5 0
! 6 0
! 7 0
! 8 0
! 9 0
! 10 0
! 11 0
! 12 0
! 13 0
! 14 0
! 15 0
! 16 0
! 17 0
! 18 0
! 19 0
! 20 0
! 21 0
! 22 0
Answer: 2 0

Case#3
! 23 59
! 1 0
! 2 0
! 3 0
! 4 0
! 5 0
! 6 0
! 7 0
! 8 0
! 9 0
! 10 0
! 11 0
! 12 0
! 13 0
! 14 0
! 15 0
! 16 0
! 17 0
! 18 0
! 19 0
Answer: 0 0

*/