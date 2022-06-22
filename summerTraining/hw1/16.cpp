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

const int maxn=15;

int t;
stack<char> s;

char get_front(char ch){
	if (ch=='>') return '<'; else
	if (ch==')') return '('; else
	if (ch==']') return '['; else
	if (ch=='}') return '{'; else
	return '*';
}

signed main(){
	t=read();
	while (t--){
		while (!s.empty()) s.pop();
		bool flg=true;
		char ch=getchar(); while (ch==10 || ch==13) ch=getchar();
		while (ch!=10 && ch!=13){
			if (flg && (ch=='>' || ch==')' || ch==']' || ch=='}')){
				if (s.empty() || s.top()!=get_front(ch)) flg=false;
				else s.pop();
			} else if (flg && (ch=='<' || ch=='(' ||ch=='[' || ch=='{')){
				s.push(ch);
			} else flg=false;
			ch=getchar();
		}
		printf((flg && s.empty())?"Yes\n":"No\n");
	}
	return 0;
}