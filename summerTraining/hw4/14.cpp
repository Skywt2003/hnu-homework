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

int n;
vector<string> a[1005];

signed main(){
	cin>>n;
	for (int i=1;i<=n;i++){
		string id; cin>>id;
		int x,y; cin>>x>>y;
		a[x*32+y].push_back(id);
	}
	for (int i=1;i<=12*32+31;i++) if (a[i].size()){
		cout<<i/32<<" "<<i%32<<" ";
		for (int j=0;j<a[i].size();j++) cout<<a[i][j]<<" ";
		cout<<endl;
	}
	return 0;
}