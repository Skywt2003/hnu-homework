#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
#include<map>

using namespace std;

const int maxn=1e6+5;

int n;
bool hand[300];
int ans=0;

map<string,int> lnt;

void build_hand(){
	string s1="qwertasdfgzxcvb QWERTASDFGZXCVB";
	string s2="yuiophjklnm YUIOPHJKLNM";
	for (int i=0;i<s1.length();i++) hand[s1[i]]=false;
	for (int i=0;i<s2.length();i++) hand[s2[i]]=true;
}

signed main(){
	build_hand();
	scanf("%d",&n);
	while (n--){
		string s; cin>>s;
		if (lnt[s]) ans+=lnt[s]/2; else{
			int now=2; int len=s.length();
			for (int i=1;i<len;i++){
				now += (hand[s[i]] == hand[s[i-1]])?4:2;
			}
			lnt[s]=now; ans+=now;
		}
	}
	printf("%d\n",ans);
	return 0;
}