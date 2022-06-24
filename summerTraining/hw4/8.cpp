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

string decode(string s){
	for (int i=0;i<s.length();i++)
		if ('A'<=s[i] && s[i]<='Z') s[i]=s[i]-5,s[i]=(s[i]<'A')?s[i]+26:s[i];
	return s;
}

signed main(){
	for (;;){
		string s; cin>>s;
		if (s=="ENDOFINPUT") break;
		getline(cin,s);
		getline(cin,s);
		cout<<decode(s)<<endl;
		cin>>s;
	}
	return 0;
}