#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
#include<cmath>
#include<map>
#include<stack>

using namespace std;
// #define int long long

inline int read(){
	int ret=0,f=1; char ch=getchar();
	while (ch<'0'||ch>'9') {if (ch=='-') f=-1;ch=getchar();}
	while (ch>='0'&&ch<='9') ret=ret*10+ch-'0',ch=getchar();
	return ret*f;
}

stack<string> s1,s2;
string now="http://www.game.org/";

signed main(){
	for (;;){
		string s; cin>>s;
		if (s=="BACK"){
			if (s2.empty()) {cout<<"Ignored"<<endl; continue;}
			s1.push(now); now=s2.top(); s2.pop();
		} else if (s=="FORWARD"){
			if (s1.empty()) {cout<<"Ignored"<<endl; continue;}
			s2.push(now); now=s1.top(); s1.pop();
		} else if (s=="VISIT"){
			s2.push(now);
			while (!s1.empty()) s1.pop();
			cin>>now;
		} else if (s=="QUIT"){
			break;
		} else cout<<"no :("<<endl;
		cout<<now<<endl;
	}
}