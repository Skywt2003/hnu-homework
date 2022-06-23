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

const int maxn=25;

int t,n=0;

struct friends{
	string name;
	vector<string> num;
};

friends a[maxn];
map<string,int> id;

int to_int(string s){
	int ret=0;
	for (int i=0;i<s.length();i++) ret=ret*10+s[i]-'0';
	return ret;
}

bool cmp(friends aa, friends bb){
	return aa.name < bb.name;
}

bool cmp2(string aa, string bb){
	if (aa.length() < bb.length()) return true;
	if (aa.length() > bb.length()) return false;
	return to_int(aa) < to_int(bb);
}

// if string b is a's suffix
bool is_suffix(string a, string b){
	int lena=a.length(),lenb=b.length();
	if (lena<lenb) return false;
	for (int i=0;i<lenb;i++) if (b[lenb-1-i] != a[lena-1-i]) return false;
	return true;
}

signed main(){
	t=read();
	while (t--){
		string s;
		cin>>s;
		if (!id[s]) id[s]=++n,a[n].name=s;
		int i=id[s];
		int x=read();
		while (x--) cin>>s,a[i].num.push_back(s);
	}
	sort(a+1,a+1+n,cmp);
	cout<<n<<endl;
	for (int i=1;i<=n;i++){
		cout<<a[i].name<<" ";
		sort(a[i].num.begin(),a[i].num.end(),cmp2);
		for (int j=0;j<a[i].num.size();j++) if (a[i].num[j]!="X")
			for (int k=0;k<a[i].num.size();k++) if (j!=k && a[i].num[k]!="X")
				if (is_suffix(a[i].num[j],a[i].num[k])) a[i].num[k]="X";
		int now_cnt=0;
		for (int j=0;j<a[i].num.size();j++) if (a[i].num[j]!="X") now_cnt++;
		cout<<now_cnt<<" ";
		for (int j=0;j<a[i].num.size();j++) if (a[i].num[j]!="X") cout<<a[i].num[j]<<" ";
		cout<<endl;
	}
}