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

int get_num(char ch){
	if (ch=='A' || ch=='B' || ch=='C') return 2; else
	if (ch=='D' || ch=='E' || ch=='F') return 3; else
	if (ch=='G' || ch=='H' || ch=='I') return 4; else
	if (ch=='J' || ch=='K' || ch=='L') return 5; else
	if (ch=='M' || ch=='N' || ch=='O') return 6; else
	if (ch=='P' || ch=='R' || ch=='S') return 7; else
	if (ch=='T' || ch=='U' || ch=='V') return 8; else
	if (ch=='W' || ch=='X' || ch=='Y') return 9; else
	return 0;
}

bool is_letter(char ch){
	return 'A'<=ch && ch<='Z';
}

bool is_number(char ch){
	return '0'<=ch && ch<='9';
}

int n;
std::map<std::string,int> cnt;

signed main(){
	n=read();
	while (n--){
		std::string s="";
		char ch=getchar();
		while (ch!=10 && ch!=13 && ch!=-1){
			if (is_number(ch)) s+=ch; else
			if (is_letter(ch)) s+=get_num(ch)+'0';
			ch=getchar();
		}
		cnt[s]++;
	}
	std::map<std::string,int>::iterator it;
	for (it=cnt.begin(); it!=cnt.end(); it++) if (it->second > 1){
		for (int i=0;i<=2;i++) putchar(it->first[i]);
		putchar('-');
		for (int i=3;i<=6;i++) putchar(it->first[i]);
		putchar(' ');
		printf("%d\n",it->second);
	}
	return 0;
}