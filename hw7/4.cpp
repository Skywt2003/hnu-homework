#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>

using namespace std;

inline int read(){
	int ret=0,f=1;char ch=getchar();
	while (ch<'0'||ch>'9') {if (ch=='-') f=-1;ch=getchar();}
	while (ch>='0'&&ch<='9') ret=ret*10+ch-'0',ch=getchar();
	return ret*f;
}

struct Jose{
    int code;
    Jose* next;
};

int n,m;

Jose* p;
Jose* tmp;

signed main(){
	n=read(), m=read();
	p = new Jose; tmp = p;
	for (int i=1; i<=n; i++){
		(*p).code = i;
		if (i==n) continue;
		p->next = new Jose;
		p = p->next;
	}
	p->next = tmp;
	p = p->next;
	for (int i=1; i<n; i++){
		for (int j=1; j<=m-2; j++) p = p->next;
		tmp = p->next->next;
		// printf("Deleted: %d\n",(*(p->next)).code);
		delete p->next;
		p->next = tmp;
		p = p->next;
	}
	printf("%d\n",(*p).code);
	return 0;
}
