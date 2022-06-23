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

struct student {
	string name,id;
	int score;
};

vector<student> vec;

bool cmp(student aa,student bb){
	return aa.score < bb.score;
}

int n;

signed main(){
	n=read();
	for (int i=0;i<n;i++){
		student now;
		cin>>now.name>>now.id>>now.score;
		vec.push_back(now);
	}
	sort(vec.begin(),vec.end(),cmp);
	cout<<vec[(int)vec.size()-1].name<<" "<<vec[(int)vec.size()-1].id<<endl;
	cout<<vec[0].name<<" "<<vec[0].id<<endl;
	return 0;
}