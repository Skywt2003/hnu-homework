#include<cstdio>
#include<cstring>
#include<iostream>
#include<fstream>

using namespace std;

int colon_pos;

bool is_content(char ch){
	return (ch!=' ' && ch!='\t' && ch!=':' && ch!=10 && ch!=13);
}

signed main(){
	cin>>colon_pos;
	// fstream fin,fout;
	// fin.open("listin.txt", ios::in);
	// fout.open("listout.txt", ios::out);
	FILE* finp = fopen("listin.txt", "r");
	FILE* foutp = fopen("listout.txt", "w");

	char ch;
	int tmp = 0; bool last_is_blank = true;
	for (;;){
		ch = getc(finp);
		if (ch == EOF) break;
		if (is_content(ch)) putc(ch, foutp), tmp++, last_is_blank = false; else
		if (ch==10 || ch==13) putc('\n', foutp), tmp = 0, last_is_blank = true; else
		if (ch==' ' || ch=='\t'){
			if (!last_is_blank) putc(' ', foutp), tmp++, last_is_blank = true;
		} else
		if (ch==':'){
			if (!last_is_blank) putc(' ', foutp), tmp++;
			for (int i=tmp; i<=colon_pos-2; i++) putc(' ', foutp);
			putc(':', foutp);
			putc(' ', foutp), last_is_blank = true;
		}
	}
	fclose(finp); fclose(foutp);
	return 0;
}