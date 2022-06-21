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

int n;

int get_num(int x){
	int ret=0;
	for (int i=1;i<=sqrt(x);i++) if (x%i==0) ret+=i + ((x/i!=i)?x/i:0);
	return ret-x;
}

signed main(){
	n=read();
	for (;;n++){
		int now=get_num(n);
		if (get_num(now) == n){
			printf("%d %d\n",n,now);
			return 0;
		}
	}
	return 0;
}