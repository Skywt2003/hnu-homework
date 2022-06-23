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

const int maxn=1005;

int n,q;

struct page{
	vector<string> name;
	vector<string> name_origin;
	int refered, id;
};

page a[maxn];

bool cmp(page aa, page bb){
	return aa.refered > bb.refered || (aa.refered == bb.refered && aa.id < bb.id);
}

bool is_uppercase(char ch){
	return 'A'<=ch && ch<='Z';
}

bool is_number(char ch){
	return '0'<=ch && ch<='9';
}

string get_lowercase(string s){
	string ret=s;
	for (int i=0;i<ret.length();i++) if (is_uppercase(ret[i])) ret[i]=ret[i]-'A'+'a';
	return ret;
}

int to_integer(string s){
	for (int i=0;i<s.length();i++) if (!is_number(s[i])) return -1;
	int ret=0;
	for (int i=0;i<s.length();i++) ret=ret*10+s[i]-'0';
	return ret;
}

void init(){
	for (int i=1;i<=n;i++)
		a[i].name.clear(),
		a[i].name_origin.clear(),
		a[i].refered=a[i].id=0;
}

signed main(){
	n=read();
	while (n){
		init();
		for (int i=1;i<=n;i++){
			string s;
			cin>>s;
			while (to_integer(s) == -1)
				a[i].name.push_back(get_lowercase(s)),
				a[i].name_origin.push_back(s),
				cin>>s;
			a[i].refered=to_integer(s);
			a[i].id=i;
		}
		sort(a+1,a+1+n,cmp);
		q=read();
		while (q--){
			vector<string> query; query.clear();
			string s="";
			char ch=getchar();
			while (ch!=10 && ch!=13){
				if (ch==' ') query.push_back(get_lowercase(s)),s="";
				else s=s+ch;
				ch=getchar();
			}
			if (s!="") query.push_back(get_lowercase(s));

			for (int i=1;i<=n;i++){
				bool can_find=true;
				for (int j=0;j<(int)query.size();j++){
					bool flg=false;
					for (int k=0;k<a[i].name.size();k++) if (a[i].name[k] == query[j]) {flg=true;break;}
					if (!flg) {can_find=false; break;}
				}
				if (can_find){
					for (int j=0;j<(int)a[i].name_origin.size()-1;j++) cout<<a[i].name_origin[j]<<" ";
					cout<<a[i].name_origin[a[i].name_origin.size()-1]<<endl;
				}
			}
			cout<<"***"<<endl;
		}
		cout<<"---"<<endl;
		n=read();
	}
}