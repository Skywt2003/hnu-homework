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
char s[maxn];

signed main(){
	for (;;){
		cin>>n;
		if (n==0) break;
		scanf("%s",s+1);
		int x=0,y=0;
		for (int i=2;i<=n;i++)
			x += (s[i-1]=='a' && s[i]=='b'),
			y += (s[i-1]=='b' && s[i]=='a');
		cout<<x-y<<endl;
	}
	return 0;
}