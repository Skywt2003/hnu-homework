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

int count(string s,int y){
	int ret=0;
	for (int i=0;i<s.length();i++) ret+=(s[i]-'0')==y;
	return ret;
}

signed main(){
	string s; cin>>s;
	int y=read();
	printf("%lld\n",count(s,y));
	return 0;
}