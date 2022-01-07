#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>

using namespace std;

const int maxn=1005;

int n,k;
int ans=0;

signed main(){
	cin>>n>>k;
	for (int i=1;i<=n;i++){
		int x; cin>>x;
		if (x%10!=k && x%k!=0) ans+=x;
	}
	cout<<ans<<endl;
	return 0;
}