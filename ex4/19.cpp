#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
#include<cmath>
#include<vector>

using namespace std;

inline int read(){
	int ret=0,f=1;char ch=getchar();
	while (ch<'0'||ch>'9') {if (ch=='-') f=-1;ch=getchar();}
	while (ch>='0'&&ch<='9') ret=ret*10+ch-'0',ch=getchar();
	return ret*f;
}

char s[10][3];

signed main(){
	for (int i=1;i<=6;i++) scanf("%s",s[i]);
	for (int i=2;i<=6;i++) if (s[i][1]==s[1][1] || s[i][0]==s[1][0]){
		printf("YES\n");
		return 0;
	}
	printf("NO\n");
	return 0;
}