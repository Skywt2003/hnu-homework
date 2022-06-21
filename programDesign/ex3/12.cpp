#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>

using namespace std;

int n,ans=0;

inline int read(){
	int ret=0,f=1;char ch=getchar();
	while (ch<'0'||ch>'9') {if (ch=='-') f=-1;ch=getchar();}
	while (ch>='0'&&ch<='9') ret=ret*10+ch-'0',ch=getchar();
	return ret*f;
}

int get_sco(char ch){
	if (ch=='r') return 1; else
	if (ch=='y') return 2; else 
	if (ch=='g') return 3; else
	if (ch=='c') return 4; else
	if (ch=='b') return 5; else 
	if (ch=='p') return 6; else
	if (ch=='B') return 7;
}

signed main(){
	n=read();
	while (n--){
		char ch=getchar(); while ((ch<'a'||ch>'z') && (ch<'A'||ch>'Z')) ch=getchar();
		int xx=1;
		if (ch=='r') xx=read();
		ans+=get_sco(ch)*xx;
	}
	printf("%d\n",ans);
	return 0;
}