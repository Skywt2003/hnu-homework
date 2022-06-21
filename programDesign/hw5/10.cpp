#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
#include<map>
#include<vector>

using namespace std;
#define int long long

inline int read(){
	int ret=0,f=1; char ch=getchar();
	while (ch<'0'||ch>'9') {if (ch=='-') f=-1;ch=getchar();}
	while (ch>='0'&&ch<='9') ret=ret*10+ch-'0',ch=getchar();
	return ret*f;
}

const int maxn=1e4+5;

int n;

signed main(){
	n=read();
	char ch=getchar();
	while (ch!=10 && ch!=13 && ch!=-1){
		if (ch>='a' && ch<='z') ch+=4,ch-=(ch>'z')?26:0;
		if (ch>='A' && ch<='Z') ch+=4,ch-=(ch>'Z')?26:0;
		putchar(ch); ch=getchar();
	}
	putchar('\n');
	return 0;
}