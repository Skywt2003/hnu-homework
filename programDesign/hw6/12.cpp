#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
#include<vector>
#include<cmath>

using namespace std;

inline int read(){
	int ret=0,f=1;char ch=getchar();
	while (ch<'0'||ch>'9') {if (ch=='-') f=-1;ch=getchar();}
	while (ch>='0'&&ch<='9') ret=ret*10+ch-'0',ch=getchar();
	return ret*f;
}

// #define int long long

bool prime(int m){
	if (m==1) return false;
	if (m==2) return true;
	for (int i=2;i<m;i++) if (m%i==0) return false;
	return true;
}

signed main(){
	int x=read(),y=read();
	int ans1=0,ans2=0;
	for (int i=x;i<=y;i++) if (prime(i)) ans1++,ans2+=i;
	printf("%d\n%d\n",ans1,ans2);
	return 0;
}