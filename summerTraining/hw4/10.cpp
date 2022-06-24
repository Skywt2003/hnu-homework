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

bool have_7(int x){
	while (x){
		if (x%10==7) return true;
		x/=10;
	}
	return false;
}

signed main(){
	int n=read();
	for (int i=1;i<=n;i++) if (i%7==0 || have_7(i)) printf("%d\n",i);
	return 0;
}