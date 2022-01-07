#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>

using namespace std;

int n;
int a[4];

bool has7(int x){
	if (x%7==0) return true;
	while (x){
		if (x%10==7) return true;
		x/=10;
	}
	return false;
}

signed main(){
	cin>>n;
	int now=1,p=0;
	while (n--){
		while (has7(now)) now++,a[p]++,p=(p+1)%4;
		now++; p=(p+1)%4;
	}
	cout<<a[0]<<endl<<a[1]<<endl<<a[2]<<endl<<a[3]<<endl;
	return 0;
}