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

int x,y,z;
int a,b,c;

signed main(){
	x=read(),y=read(),z=read();
	int tot1 = x*17*29 + y*29 + z;
	a=read(),b=read(),c=read();
	int tot2 = a*17*29 + b*29 + c;
	bool fu=(tot1>tot2);
	if (fu) std::swap(tot1,tot2),putchar('-');

	int change = tot2-tot1;
	printf("%d.%d.%d\n",change/(17*29),change%(17*29)/29,change%29);
}