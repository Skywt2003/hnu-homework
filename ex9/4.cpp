#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

inline int read(){
	int ret=0,f=1;char ch=getchar();
	while (ch<'0'||ch>'9') {if (ch=='-') f=-1;ch=getchar();}
	while (ch>='0'&&ch<='9') ret=ret*10+ch-'0',ch=getchar();
	return ret*f;
}

struct red_card{
	bool master;
	int time;
	int id;
};

vector<red_card> vec;

const int maxn=95,maxx=25;

char s1[maxx],s2[maxx];
int n;

bool yed[2][maxn];

bool cmp(red_card aa,red_card bb){
	return (aa.time<bb.time) || (aa.time==bb.time && aa.master>bb.master) || (aa.time==bb.time && aa.master==bb.master && aa.id>bb.id);
}

signed main(){
	scanf("%s",s1); scanf("%s",s2);
	n=read();
	while (n--){
		int t=read();
		char m=getchar(); while (m!='h'&&m!='a') m=getchar();
		int id=read();
		char y=getchar(); while (y!='y'&&y!='r') y=getchar();

		if (y=='r' || (y=='y' && yed[m=='h'][id])) vec.push_back((red_card){m=='h', t, id});
		else yed[m=='h'][id]=true;
	}
	sort(vec.begin(),vec.end(),cmp);
	if (vec.size() == 0) printf("No Red Card\n");
	else {
		for (int i=0;i<(int)vec.size();i++) printf("%s %d %d\n",(vec[i].master)?s1:s2, vec[i].id, vec[i].time);
	}
	return 0;
}