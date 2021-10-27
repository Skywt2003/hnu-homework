#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
#include<map>
#include<vector>

using namespace std;
#define int long long

inline int read(){
	int ret=0,f=1; char ch=getchar();
	while (ch<'0'||ch>'9') {if (ch=='-') f=-1;ch=getchar();}
	while (ch>='0'&&ch<='9') ret=ret*10+ch-'0',ch=getchar();
	return ret*f;
}

const int maxn=100+5;

string s1,s2;

char lowercase(char ch){
	if (ch>='A' && ch<='Z') ch=ch-'A'+'a';
	return ch;
}

signed main(){
	s1="";s2="";
	char ch=getchar();
	while (ch!=10 && ch!=13){
		if (ch!=' ') s1+=lowercase(ch);
		ch=getchar();
	}
	while (ch==10 || ch==13) ch=getchar();
	while (ch!=10 && ch!=13 && ch!=-1){
		if (ch!=' ') s2+=lowercase(ch);
		ch=getchar();
	}
	printf((s1==s2)?"1\n":"0\n");
	return 0;
}