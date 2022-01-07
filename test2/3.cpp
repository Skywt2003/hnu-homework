#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>

using namespace std;

string s;
int len;
int ans=0,now=0;

bool is_letter(char ch){
	return (ch>='a'&&ch<='z') || (ch>='A'&&ch<='Z');
}

signed main(){
	getline(cin, s);
	len = s.length();
	for (int i=0;i<len;i++){
		if (is_letter(s[i])) now++;
		else if (now) ans=now, now=0;
	}
	if (now) ans=now,now=0;
	cout<<ans<<endl;
	return 0;
}