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

int cnt[10];

bool is_digit(char ch){
	return '0'<=ch && ch<='9';
}

signed main(){
	char ch=getchar();
	while (is_digit(ch)) cnt[ch-'0']++,ch=getchar();
	for (int i=0;i<10;i++) if (cnt[i]) printf("%d:%d\n",i,cnt[i]);
	return 0;
}