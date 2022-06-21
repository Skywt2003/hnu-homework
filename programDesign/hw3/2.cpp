#include<cstdio>
#include<cstring>
#include<iostream>

using namespace std;

inline int read(){
	int ret=0,f=1;char ch=getchar();
	while (ch<'0'||ch>'9') {if (ch=='-') f=-1;ch=getchar();}
	while (ch>='0'&&ch<='9') ret=ret*10+ch-'0',ch=getchar();
	return ret*f;
}

int n;
string ans;

signed main(){
	scanf("%d",&n); ans="";
	while (n) ans=((n&1)?"1":"0")+ans,n>>=1;
	cout<<ans<<endl;
	return 0;
}