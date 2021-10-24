#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>

using namespace std;

int x,y;
char ch;

inline int read(){
	int ret=0,f=1;char ch=getchar();
	while (ch<'0'||ch>'9') {if (ch=='-') f=-1;ch=getchar();}
	while (ch>='0'&&ch<='9') ret=ret*10+ch-'0',ch=getchar();
	return ret*f;
}

signed main(){
	int max_sco=-1,max_id=0;
	for (int i=0;i<3;i++){
		x=read();
		ch=getchar(); while (ch!='y' && ch!='n') ch=getchar();
		y=read();
		int sco = (x/5000*100) + 20*(ch=='y') + max(0, 100-10*(y-2000-1)/200+1);
		if (sco > max_sco) max_sco=sco,max_id=i;
	}
	putchar(max_id+'A'); putchar('\n');
	return 0;
}