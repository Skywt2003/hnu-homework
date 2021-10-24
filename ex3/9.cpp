#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>

using namespace std;

char ch;

string num[10]={"Zero", "One", "Two", "Three", "Four", "Five", "Six", "Seven", "Eight", "Nine"};

signed main(){
	ch=getchar();
	if (ch>='0'&&ch<='9') cout<<num[ch-'0']<<endl;
	else printf("Other\n");
	return 0;
}