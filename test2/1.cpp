#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>

using namespace std;

const int maxn=1e5+5;

int n,a[maxn];

signed main(){
	cin>>n;
	for (int i=1;i<=n;i++) cin>>a[i];
	sort(a+1,a+1+n);
	cout<<a[n]<<" ";
	if (n&1) cout<<a[(n+1)/2];
	else{
		// cout<<1.0*(a[n/2]+a[n/2+1])/2.0;
		if ((a[n/2]+a[n/2+1])&1) cout<<(a[n/2]+a[n/2+1])/2<<".5";
		else cout<<(a[n/2]+a[n/2+1])/2;
	}
	cout<<" "<<a[1]<<endl;
	return 0;
}