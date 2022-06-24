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

int get_answer(string s){
	int cnt=0;
	for (int i=0;i<s.length();i++){
		if (s[i] == 'B') return cnt; else
		cnt+=(s[i]=='(')?1:-1;
	}
	return -1;
}

signed main(){
	string s;
	while (cin>>s) cout<<get_answer(s)<<endl;
}