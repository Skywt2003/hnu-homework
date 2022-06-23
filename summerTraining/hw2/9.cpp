#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
#include<cmath>
#include<map>

// using namespace std;
// #define int long long

inline int read(){
	int ret=0,f=1; char ch=getchar();
	while (ch<'0'||ch>'9') {if (ch=='-') f=-1;ch=getchar();}
	while (ch>='0'&&ch<='9') ret=ret*10+ch-'0',ch=getchar();
	return ret*f;
}

int n;

int win,lose,draw;

bool can_win(std::string aa, std::string bb){
	if (aa=="B") return (bb=="C"); else
	if (aa=="J") return (bb=="B"); else
	if (aa=="C") return (bb=="J"); else
	std::cout<<"No such ges"<<std::endl;
	return 0;
}

int get_num(std::string aa){
	if (aa=="B") return 0; else
	if (aa=="C") return 1; else
	if (aa=="J") return 2; else
	std::cout<<"No such ges"<<std::endl;
	return 0;
}

char get_char(int x){
	if (x==0) return 'B'; else
	if (x==1) return 'C'; else
	if (x==2) return 'J'; else
	return 'X';
}

int ges[2][3];

signed main(){
	n=read();
	for (int i=1;i<=n;i++){
		std::string s1,s2;
		std::cin>>s1>>s2;
		if (s1 == s2) draw++; else
		if (can_win(s1,s2)) win++,ges[0][get_num(s1)]++;
		else lose++,ges[1][get_num(s2)]++;
	}
	std::cout<<win<<" "<<draw<<" "<<lose<<std::endl;
	std::cout<<lose<<" "<<draw<<" "<<win<<std::endl;
	int now_max=0;
	if (ges[0][1] > ges[0][now_max]) now_max=1;
	if (ges[0][2] > ges[0][now_max]) now_max=2;
	putchar(get_char(now_max));
	now_max=0;
	if (ges[1][1] > ges[1][now_max]) now_max=1;
	if (ges[1][2] > ges[1][now_max]) now_max=2;
	putchar(' ');
	putchar(get_char(now_max));
	printf("\n");
	return 0;
}