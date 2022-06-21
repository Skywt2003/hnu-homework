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

int n;

bool is_prime(int x){
	if (x==1) return false;
	if (x==2) return true;
	for (int i=2;i<=sqrt(x);i++) if (x%i==0) return false;
	return true;
}

int devide_prime(int x){
	int ret=0;
	for (int i=2;i<=x && x>1;i++)
		if (is_prime(i) && x%i==0) x/=i,ret++;
	return (x==1)?ret:-1;
}

signed main(){
	n=read();
	if (n==1) printf("1\n"); else{
		int k=devide_prime(n);
		if (k!=-1) printf("%lld\n",(k&1)?-1LL:1LL);
		else printf("0\n");
	}
	return 0;
}

// 输出一定要严格对应 %lld 和 long long 类型！！！不然很容易输出乱码。