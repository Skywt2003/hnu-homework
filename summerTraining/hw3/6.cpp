#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
#include<cmath>
#include<map>

using namespace std;
// #define int long long

inline int read(){
	int ret=0,f=1; char ch=getchar();
	while (ch<'0'||ch>'9') {if (ch=='-') f=-1;ch=getchar();}
	while (ch>='0'&&ch<='9') ret=ret*10+ch-'0',ch=getchar();
	return ret*f;
}

int cnt[10];

bool is_digit(char ch){
	return '0'<=ch && ch<='9';
}

string get_name(int x){
	cnt[x]++;
	if (x==0) return "(Zero)";
	if (x==1) return "(One)";
	if (x==2) return "(Two)";
	if (x==3) return "(Three)";
	if (x==4) return "(Four)";
	if (x==5) return "(Five)";
	if (x==6) return "(Six)";
	if (x==7) return "(Seven)";
	if (x==8) return "(Eight)";
	if (x==9) return "(Nine)";
	return "None";
}

signed main(){
	char ch=getchar();
	while (ch!=10 && ch!=13 && ch!=-1){
		if (is_digit(ch)) cout<<get_name(ch-'0');
		else putchar(ch);
		ch=getchar();
	}
	putchar('\n');
	for (int i=0;i<10;i++) printf("%d ",cnt[i]);
	printf("\n");
}