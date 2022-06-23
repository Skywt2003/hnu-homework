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

// Haab
string haa[19]={"pop", "no", "zip", "zotz", "tzec", "xul", "yoxkin", "mol", "chen", "yax", "zac", "ceh", "mac", "kankin", "muan", "pax", "koyab", "cumhu", "uayet"};

// Tzolkin
string tzo[20]={"imix", "ik", "akbal", "kan", "chicchan", "cimi", "manik", "lamat", "muluk", "ok", "chuen", "eb", "ben", "ix", "mem", "cib", "caban", "eznab", "canac", "ahau"};

int t;

int get_month(string s){
	for (int i=0;i<19;i++) if (s==haa[i]) return i+1;
	cout<<"Not month!"<<endl;
	return 0;
}

signed main(){
	t=read();
	while (t--){
		string month;

		int day=read();
		cin>>month;
		int year=read();
		int tot_day = year*365 + (get_month(month)-1)*20 + day;
		
		year = tot_day / 260; tot_day%=260;
		int x=0,y=0;
		while (tot_day) x=(x+1)%20,y=(y+1)%13,tot_day--;
		cout<<y+1<<" "<<tzo[x]<<" "<<year<<endl;
	}
	return 0;
}