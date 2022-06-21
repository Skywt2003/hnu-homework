#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>

using namespace std;

const int maxn=1e6+5;

int n;
char s[maxn];
string ans="";

signed main(){
	scanf("%s",s+1); n=strlen(s+1);
	bool flg=false;
	for (int i=1;i<=n;i++){
		if (i+2<=n && s[i]=='W' && s[i+1]=='U' && s[i+2]=='B') flg=true,i+=2;
		else {
			if (flg && ans!="") ans+=' ';
			flg=false;
			ans+=s[i];
		}
	}
	cout<<ans<<endl;
	return 0;
}