#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>

using namespace std;

string s1,s2;
string ans="";

int len1,len2;

bool is_sm_letter(char ch){return 'a'<=ch && ch<='z';}
bool is_bg_letter(char ch){return 'A'<=ch && ch<='Z';}

signed main(){
	cin>>s1>>s2;
	len1=s1.length(); len2=s2.length();

	for (int i=0;i<len2;i++)
		if (is_sm_letter(s2[i])) ans+=s2[i]; else
		if (is_bg_letter(s2[i])) ans+=s2[i]-'A'+'a';
	for (int i=0;i<len1;i++)
		if (is_sm_letter(s1[i])) ans+=s1[i]; else
		if (is_bg_letter(s1[i])) ans+=s1[i]-'A'+'a';

	cout<<ans<<endl;
	return 0;
}
