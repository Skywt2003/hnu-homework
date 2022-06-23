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

map<string,string> dict;
map<string,string> reverse_dict;

signed main(){
	string now,line,tmp;
	// cin>>now;
	// while (now!="@END@"){
	// 	getchar();
	// 	getline(cin, line);
	// 	dict[now]=line;
	// 	string tmp="";
	// 	for (int i=1;i<now.length()-1;i++) tmp+=now[i];
	// 	reverse_dict[line]=tmp;
	// 	cin>>now;
	// }

	// 魔咒中可能包含空格！
	char ch=getchar();
	while (ch!='@'){
		now=""; now+=ch; tmp=""; ch=getchar();
		while (ch!=']') now=now+ch,tmp=tmp+ch,ch=getchar();
		now=now+ch;
		getchar();
		getline(cin, line);
		dict[now]=line;
		reverse_dict[line]=tmp;
		ch=getchar();
	}
	// int q;
	// cin>>q; getline(cin,now);
	int q=read();
	while (q--){
		getline(cin,now);
		if (now[0]=='['){
			if (dict[now]!="") cout<<dict[now]<<endl;
			else cout<<"what?"<<endl;
		} else {
			if (reverse_dict[now]!="") cout<<reverse_dict[now]<<endl;
			else cout<<"what?"<<endl;
		}
	}
	return 0;
}