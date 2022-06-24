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

string s1,s2;
int left_wildcard[15];

void build_left(){
	memset(left_wildcard,0,sizeof(left_wildcard));
	for (int i=s1.length()-2;i>=0;i--) left_wildcard[i]=left_wildcard[i+1]+(s1[i+1]=='?');
}

int power10(int x){
	int ret=1;
	while (x--) ret*=10;
	return ret;
}

int get_num(int s){
	if (s >= s1.length()) return 0;
	if (s1[s]=='?'){
		int x=s2[s]-'0';
		int ret=0;
		s1[s]=x+'0';
		ret = get_num(s+1);
		s1[s]='?';
		return ret + (9-x)*power10(left_wildcard[s]);
	} else if (s1[s]>s2[s]){
		return power10(left_wildcard[s]);
	} else if (s1[s]<s2[s]){
		return 0;
	} else if (s1[s]==s2[s]){
		if (s == s1.length()-1) return s1>=s2;
		return get_num(s+1);
	}
	return 0;
}

signed main(){
	while (cin>>s1>>s2) build_left(),cout<<get_num(0)<<endl;
	return 0;
}