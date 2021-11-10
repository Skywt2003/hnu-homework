#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

inline int read(){
	int ret=0,f=1;char ch=getchar();
	while (ch<'0'||ch>'9') {if (ch=='-') f=-1;ch=getchar();}
	while (ch>='0'&&ch<='9') ret=ret*10+ch-'0',ch=getchar();
	return ret*f;
}

#define int long long

int x,num;
bool flg=true;

int MakeNumber(){
	return 35;
}

void GuessNumber(int magic){
	if (magic==num) printf("Right!\n"),flg=false; else
	if (magic<num) printf("Wrong! Too low!\n"); else
	if (magic>num) printf("Wrong! Too high!\n");
}

signed main(){
	int cnt=0;
	num=MakeNumber();
	for (;;){
		cnt++;
		if (cnt>5) return 0;
		GuessNumber(read());
		if (!flg) return 0;
	}
	return 0;
}