#include<cstdio>
#include<cstring>
#include<iostream>
#include<map>

using namespace std;

class file{
	public:
		string name;
		string content;

		file(){
			cout<<"<Created file: ";
			name = "newFIle";
		}
		virtual ~file(){
			cout<<"file removed>"<<endl;
		}
		virtual void open() = 0;
};

class txt: public file{
	public:
		// txt(){cout<<this->name<<".txt>"<<endl;}
		txt(string& s){
			this->name=s;
			cout<<this->name<<".txt>"<<endl;
		}
		~txt(){cout<<"<"<<this->name<<".txt ";}

		void open(){
			cout<<"<Opening "<<this->name<<".txt>"<<endl;
			cout<<content<<endl;
		}
};

class exe: public file{
	public:
		// exe(){cout<<this->name<<"exe>"<<endl;}
		exe(string& s){
			this->name=s;
			cout<<this->name<<"exe>"<<endl;
		}
		~exe(){cout<<"<"<<this->name<<".exe ";}

		void open(){
			cout<<"<Running "<<this->name<<".exe>"<<endl;
			cout<<"Nothing to do."<<endl;
		}
};

map<string, file*> link;

void showHelpInfo(){
	cout<<"possible commands: "<<endl;
	cout<<" help: show this help info."<<endl;
	cout<<" create: create a file."<<endl;
	cout<<" remove: remove a file."<<endl;
	cout<<" open: open a file."<<endl;
	cout<<" exit: exit the program."<<endl;
}

void createFile(){
	cout<<"File name: ";
	string name; cin>>name;
	string type;
	while (type!="exe" && type!="txt"){
		cout<<"File type (txt/exe): ";
		cin>>type;
	}
	if (type=="exe"){
		link[name] = new exe(name);
	} else {
		cout<<"File content: ";
		string content; //cin>>content;
		getline(cin, content); getline(cin, content);
		link[name] = new txt(name);
		link[name]->content = content;
	}
}

void removeFile(){
	cout<<"File name: ";
	string name; cin>>name;
	if (link[name]){
		delete link[name];
		link[name] = NULL;
	} else {
		cout<<"No file called "<<name<<" exsits!"<<endl;
	}
}

void openFile(){
	cout<<"File name: ";
	string name; cin>>name;
	link[name]->open();
}

int exitProgram(){
	cout<<"Bye"<<endl;
	return 0;
}

signed main(){
	cout<<"Welcome :) What do you want to do?"<<endl;
	cout<<"Enter 'help' to see help info."<<endl;
	for (;;){
		cout<<endl<<"skywt > ";
		string opt; cin>>opt;
		if (opt=="help") showHelpInfo(); else
		if (opt=="create") createFile(); else
		if (opt=="remove") removeFile(); else
		if (opt=="open") openFile(); else
		if (opt=="exit") return exitProgram(); else
		cout<<"Invalid command! Please try again. "<<endl;
	}
	return 0;
}