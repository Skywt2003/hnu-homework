// n 关键字排序

#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
#include<cmath>
#include<map>
#include<stack>

using namespace std;
// #define int long long

inline int read(){
	int ret=0,f=1; char ch=getchar();
	while (ch<'0'||ch>'9') {if (ch=='-') f=-1;ch=getchar();}
	while (ch>='0'&&ch<='9') ret=ret*10+ch-'0',ch=getchar();
	return ret*f;
}

const int maxn=205;

map<string, int> id;

struct car {
	string name;
	int score;
	int cnt[105];
};

car a[maxn];

const int delta_rating[11]={0,25,18,15,12,10,8,6,4,2,1};

int t,n=0;

bool cmp1(car aa,car bb){
	if (aa.score > bb.score) return true;
	if (aa.score < bb.score) return false;
	for (int i=1;i<=100;i++){
		if (aa.cnt[i] > bb.cnt[i]) return true;
		if (aa.cnt[i] < bb.cnt[i]) return false;
	}
	// printf("Not sure finally.");
	// 只需要找到冠军，即使后面有无法比较的也无妨
	return false;
}

bool cmp2(car aa,car bb){
	if (aa.cnt[1] > bb.cnt[1]) return true;
	if (aa.cnt[1] < bb.cnt[1]) return false;
	if (aa.score > bb.score) return true;
	if (aa.score < bb.score) return false;
	for (int i=2;i<=100;i++){
		if (aa.cnt[i] > bb.cnt[i]) return true;
		if (aa.cnt[i] < bb.cnt[i]) return false;
	}
	// printf("Not sure finally.");
	return false;
}

signed main(){
	t=read();
	while (t--){
		int now=read();
		for (int i=1;i<=now;i++){
			string s; cin>>s;
			if (!id[s]) id[s]=++n,a[n].name=s;
			int now_id=id[s];
			if (i <= 10) a[now_id].score+=delta_rating[i];
			a[now_id].cnt[i]++;
		}
	}
	sort(a+1,a+1+n,cmp1);
	cout<<a[1].name<<endl;
	sort(a+1,a+1+n,cmp2);
	cout<<a[1].name<<endl;
}