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

int get_num(int x){
	int ret=0;
	for (int i=1;i<=sqrt(x);i++) if (x%i==0) ret+=i + ((x/i!=i)?x/i:0);
	return ret-x;
}

signed main(){
	n=read();
	printf((get_num(n) == n)?"true\n":"false\n");
	return 0;
}