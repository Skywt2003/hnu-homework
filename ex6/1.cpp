#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
#include<vector>

#include "magic.h"

using namespace std;

inline int read(){
	int ret=0,f=1;char ch=getchar();
	while (ch<'0'||ch>'9') {if (ch=='-') f=-1;ch=getchar();}
	while (ch>='0'&&ch<='9') ret=ret*10+ch-'0',ch=getchar();
	return ret*f;
}

int num;

signed main(){
	bool flg=isMagic(read());
	if (flg) printf("YES\n"); else printf("NO\n");
	return 0;
}

bool isMagic(int a){
	int ones=0,fours=0;
	while (a){
		if (a%10==4) ones=0,fours++;
		else if (a%10==1) ones++,fours=0;
		else return false;
		if (fours>2) return false;
		a/=10;
	}
	if (fours) return false;
	return true;
}