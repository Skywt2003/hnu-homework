#include<cstdio>
#include<cstring>
#include<iostream>

using namespace std;

inline int read(){
	int ret=0,f=1;char ch=getchar();
	while (ch<'0'||ch>'9') {if (ch=='-') f=-1;ch=getchar();}
	while (ch>='0'&&ch<='9') ret=ret*10+ch-'0',ch=getchar();
	return ret*f;
}

int n;

bool check_seven(int x){
	while (x){
		if (x%10 == 7) return true;
		x/=10;
	}
	return false;
}

signed main(){
	scanf("%d",&n);
	for (int i=7;i<=n;i++) if (i%7==0 || check_seven(i)) printf("%d\n",i);
	return 0;
}