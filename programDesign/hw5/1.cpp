#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
#include<map>

using namespace std;
#define int long long

inline int read(){
	int ret=0,f=1; char ch=getchar();
	while (ch<'0'||ch>'9') {if (ch=='-') f=-1;ch=getchar();}
	while (ch>='0'&&ch<='9') ret=ret*10+ch-'0',ch=getchar();
	return ret*f;
}

int n;
int x_1=-1LL,y_1,x_2=-1LL,y_2;

signed main(){
	n=read();
	for (int i=1;i<=n;i++)
		for (int j=1;j<=n;j++){
			int x=read();
			if (!x){
				if (x_1==-1) x_1=i,y_1=j;
				else x_2=i,y_2=j;
			}
		}
	printf("%lld\n",(x_2-x_1-1)*(y_2-y_1-1));
	return 0;
}