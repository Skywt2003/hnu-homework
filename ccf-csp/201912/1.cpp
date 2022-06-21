#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>

using namespace std;

inline int read(){
	int ret=0,f=1;char ch=getchar();
	while (ch<'0'||ch>'9') {if (ch=='-') f=-1;ch=getchar();}
	while (ch>='0'&&ch<='9') ret=ret*10+ch-'0',ch=getchar();
	return ret*f;
}

int n,num=0,prt=3;
int cnt[5];

bool check_seven(int x){
	if (x%7 == 0) return true;
	while (x){
		if (x%10 == 7) return true;
		x/=10;
	}
	return false;
}

signed main(){
	n=read();
	for (int i=1;i<=n;i++){
		num++; prt=(prt+1)%4;
		while (check_seven(num)) cnt[prt]++,prt=(prt+1)%4,num++;
	}
	for (int i=0;i<4;i++) printf("%d\n",cnt[i]);
	return 0;
}