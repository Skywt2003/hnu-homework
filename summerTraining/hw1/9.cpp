#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
#include<cmath>
#include<map>

// using namespace std;
// #define int long long

inline int read(){
	int ret=0,f=1; char ch=getchar();
	while (ch<'0'||ch>'9') {if (ch=='-') f=-1;ch=getchar();}
	while (ch>='0'&&ch<='9') ret=ret*10+ch-'0',ch=getchar();
	return ret*f;
}

int n,p1,p2,p3,t1,t2;
int last;
int ans=0;

signed main(){
	n=read(); p1=read(),p2=read(),p3=read(),t1=read(),t2=read();
	for (int i=1;i<=n;i++){
		int li=read(),ri=read();
		if (i!=1){
			if (li-last > t1+t2) ans += p1*t1 + p2*t2 + p3*(li-last-t1-t2); else
			if (li-last > t1) ans += p1*t1 + p2*(li-last-t1); else
			ans+=p1*(li-last);
 		}
		ans+=(ri-li)*p1;
		last=ri;
	}
	printf("%d\n",ans);
	return 0;
}

/*
[20,30]  11 * 8 = 88
[31,49]  19: 4 * 8 + 6 * 4 + 9 * 2 = 74
//[31,49]  19: 5 * 8 + 10 * 4 + 4 * 2 = 88
[50,100] 51 * 8 = 408
*/