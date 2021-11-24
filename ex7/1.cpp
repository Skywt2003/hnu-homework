#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>

using namespace std;

int t,n;
string s;

signed main(){
	cin>>t;
	while (t--){
		cin>>n>>s;
		int num1=0,num2=0;
		for (int i=1;i<n;i++)
			num1+=(s[i]=='T' && s[i-1]=='S'),
			num2+=(s[i]=='S' && s[i-1]=='T');
		printf((num1>num2)?"YES\n":"NO\n");
	}
	return 0;
}