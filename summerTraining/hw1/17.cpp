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

const int maxn=50;

int n;
map<string, int> id;

struct team{
	string name;
	int rating, net, get;
};
team a[maxn];

bool is_letter(char ch){
	return ('a'<=ch && ch<='z') || ('A'<=ch && ch<='Z');
}

bool cmp(team aa, team bb){
	return (aa.rating > bb.rating ||
	(aa.rating == bb.rating && aa.net > bb.net) ||
	(aa.rating == bb.rating && aa.net == bb.net && aa.get > bb.get));
}

bool cmp_dict(team aa, team bb){
	return aa.name < bb.name;
}

signed main(){
	n=read();
	for (int i=1;i<=n;i++) cin>>a[i].name,id[a[i].name]=i;
	for (int i=1;i<=n*(n-1)/2;i++){
		string s1="",s2="";
		char ch=getchar();
		while (!is_letter(ch)) ch=getchar();
		while (ch!='-') s1+=ch,ch=getchar();
		while (!is_letter(ch)) ch=getchar();
		while (ch!=' ') s2+=ch,ch=getchar();
		int x1=read(),x2=read();
		int id1=id[s1],id2=id[s2];
		if (x1==x2) a[id1].rating++,a[id2].rating++; else
		if (x1>x2) a[id1].rating+=3; else a[id2].rating+=3;
		a[id1].net+=x1-x2; a[id2].net+=x2-x1;
		a[id1].get+=x1; a[id2].get+=x2;
	}
	sort(a+1,a+1+n,cmp);
	sort(a+1,a+1+n/2,cmp_dict);
	for (int i=1;i<=n/2;i++) cout<<a[i].name<<endl;
	return 0;
}