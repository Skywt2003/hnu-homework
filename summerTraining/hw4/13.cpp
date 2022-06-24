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

int m1,m2,r1,r2,r3;
string s;

signed main(){
	while (cin>>m1>>m2){
		cin>>s;
		for (int i=0;i<s.length();i++){
			if (s[i]=='A') r1=m1; else
			if (s[i]=='B') r2=m2; else
			if (s[i]=='C') m1=r3; else
			if (s[i]=='D') m2=r3; else
			if (s[i]=='E') r3=r1+r2; else
			if (s[i]=='F') r3=r1-r2;
		}
		cout<<m1<<","<<m2<<endl;
	}
	return 0;
}