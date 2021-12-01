#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>

using namespace std;

struct obj{
	string s;
	int a[4];
};

const int maxn=10005;

int n=0,x;
obj a[maxn];

bool cmp(obj aa,obj bb){
	return aa.a[x] > bb.a[x];
}

signed main(){
	for (;;){
		string s; cin>>s;
		if (s=="#") break;
		n++; a[n].s=s;
		scanf("%d%d%d",&a[n].a[1],&a[n].a[2],&a[n].a[3]);
	}
	cin>>x;
	sort(a+1,a+1+n,cmp);
	for (int i=1;i<=n;i++){
		cout<<a[i].s<<" "<<a[i].a[1]<<" "<<a[i].a[2]<<" "<<a[i].a[3]<<endl;
	}
	return 0;
}