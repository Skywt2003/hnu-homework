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

int n;

vector<bool> vec[2];

signed main(){
	n=read();
	while (n){
		vec[0].clear(),vec[1].clear();
		for (int i=0;i<n;i++){
			string s; cin>>s;
			while (s!="no" && s!="good") cin>>s;
			vec[i&1].push_back(s=="good");
			if (s=="no") cin>>s;
		}

		for (int i=0;i<vec[0].size();i++) cout<<i+1<<" ";
		cout<<"Score"<<endl;
		int cnt=0;
		for (int i=0;i<vec[0].size();i++){
			cout<<(vec[0][i]?"O":"X")<<" ";
			cnt+=vec[0][i];
		}
		cout<<cnt<<endl;
		cnt=0;
		for (int i=0;i<vec[1].size();i++){
			cout<<(vec[1][i]?"O":"X")<<" ";
			cnt+=vec[1][i];
		}
		if (vec[0].size() != vec[1].size()) cout<<"- ";
		cout<<cnt<<endl;
		n=read();
	}
	return 0;
}