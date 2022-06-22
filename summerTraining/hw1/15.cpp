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

const int maxn=15;

int t,cnt;

map<string, int> id;
string name[maxn];

int net_win[maxn],rating[maxn];

bool bigger(int i,int j){
	if (j==-1) return true;
	return (rating[i]>rating[j] || (rating[i]==rating[j] && net_win[i]>net_win[j]));
}

signed main(){
	t=read();
	while (t--){
		memset(net_win,0,sizeof(net_win));
		memset(rating,0,sizeof(rating));
		id.clear();
		cnt=0;
		for (int i=1;i<=12;i++){
			string s1,s2,tmp;
			int x1,x2;
			cin>>s1>>x1>>tmp>>x2>>s2;
			// cout<<"fuck "<<s1<<" "<<x1<<" "<<x2<<" "<<s2<<endl;
			if (!id[s1]) id[s1]=++cnt,name[cnt]=s1;
			if (!id[s2]) id[s2]=++cnt,name[cnt]=s2;
			if (x1==x2) rating[id[s1]]++,rating[id[s2]]++; else
			if (x1>x2) rating[id[s1]]+=3; else rating[id[s2]]+=3;
			net_win[id[s1]]+=x1-x2;
			net_win[id[s2]]+=x2-x1;
		}
		int rank1=-1,rank2=-1;
		for (int i=1;i<=cnt;i++)
			if (bigger(i,rank1)) rank2=rank1,rank1=i; else
			if (bigger(i,rank2)) rank2=i;
		cout<<name[rank1]<<" "<<name[rank2]<<endl;
	}
	return 0;
}