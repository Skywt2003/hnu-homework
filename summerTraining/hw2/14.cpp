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

char s[25];

signed main(){
	int n=read();
	while (n){
		memset(s,0,sizeof(s));
		for (int i=1;i<=2*n-1;i++){
			char tmp[25];
			scanf("%s",tmp);
			for (int i=0;i<strlen(tmp);i++) s[i]^=tmp[i];
		}
		for (int i=0;i<20 && s[i];i++) putchar(s[i]);
		putchar('\n');
		n=read();
	}
	return 0;
}