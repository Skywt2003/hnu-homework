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

int w[17]={7,9,10,5,8,4,2,1,6,3,7,9,10,5,8,4,2};
char c[11]={'1','0','X','9','8','7','6','5','4','3','2'};

string s;

signed main(){
	for (;;){
		cin>>s;
		if (s=="-1") break;
		int sum=0;
		for (int i=0;i<17;i++) sum+=(s[i]-'0')*w[i];
		sum%=11;
		printf((c[sum]==s[17])?"1\n":"0\n");
	}
	return 0;
}