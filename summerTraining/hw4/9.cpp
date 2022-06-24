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

const int maxn=100005;

int n;
string s;

signed main(){
	for (;;){
		cin>>n; if (!n) break;
		cin>>s;
		string rev_s=s;
		reverse(rev_s.begin(),rev_s.end());
		if (s==rev_s){
			printf("0\n");
			continue;
		}
		string now=""; int ans=0;
		for (int i=(int)rev_s.length()-1;i>=0;i--){
			now=rev_s[i]+now; ans++;
			string ss=s+now;
			string rev_ss=ss;
			reverse(rev_ss.begin(),rev_ss.end());
			// cout<<"i="<<i<<", ss="<<ss<<", ss_rev="<<rev_ss<<endl;
			if (ss == rev_ss){
				printf("%d\n",ans);
				break;
			}
		}
	}
}