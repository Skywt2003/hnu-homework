#include <iostream>
#include <iomanip>
#include <fstream>
using namespace std;

struct Student{
	char ID[12]; //ѧ��
	double score; //�ܷ�
	double sco[9]; //��С��÷�
};

//�����i��ѧ������Ϣ
void Print_Info(Student stu[],int i){
	cout <<setw(12)<<"ID";
	cout<<setw(7)<<"Score"<<setw(6)<<"q1";
	cout<<setw(6)<<"q2"<<setw(6)<<"q3"<<setw(6)<<"q4"<<setw(6)<<"q5";
	cout<<setw(6)<<"q6"<<setw(6)<<"q7"<<setw(6)<<"q8"<<setw(6)<<"q9\n";
	for(int j=0;j<12;j++)
		putchar(stu[i].ID[j]);
	cout<<setw(7)<<stu[i].score;
	for(int j = 0;j < 9;j++)
		cout<<setw(5)<<stu[i].sco[j]<<' ';
	cout<<endl;
}

//�������ѧ������Ϣ
void Print_AllInfo(Student stu[],int Num_Stu){
	cout <<setw(12)<<"ID";
	cout<<setw(7)<<"Score"<<setw(6)<<"q1";
	cout<<setw(6)<<"q2"<<setw(6)<<"q3"<<setw(6)<<"q4"<<setw(6)<<"q5";
	cout<<setw(6)<<"q6"<<setw(6)<<"q7"<<setw(6)<<"q8"<<setw(6)<<"q9\n";
	for(int i=0;i<Num_Stu;i++){
		for(int j=0;j<12;j++) putchar(stu[i].ID[j]);
		cout<<setw(7)<<stu[i].score;
		for(int j = 0;j < 9;j++)
			cout<<setw(5)<<stu[i].sco[j]<<' ';
		cout<<endl;
	}
}

//�����߷�
void Print_Max(Student stu[],int Num_Stu);

//�����ͷ�
void Print_Min(Student stu[],int Num_Stu);

//���ƽ����
void Print_Average(Student stu[],int Num_Stu);

//�����������,������ͬ�������ѧ�ſ�ǰ��
void Print_sort(Student stu[],int Num_Stu);

//���С��÷��ʣ�С�����1-5ѡ��6-8��̣�9Ƭ�α��
void Print_Question(Student stu[],int Num_Stu);

//����������ʾ
void Print_Stage(Student stu[],int Num_Stu);


Student stu[50];
int main(){
	int Num_Stu = 35;                //ѧ������
	// fstream Semi;
	// Semi.open("midtest-aq1.txt");       //�ļ��������޸ģ��ļ�·����cpp��ͬһ�ļ�����
	freopen("midtest-aq1.txt","r",stdin);
	// is_open���ļ��Ƿ������� 
    // if(!Semi.is_open()){
    // 	cout<<"error opening file\n";
    // 	return 1;
    // }
    // eof�����ļ������ļ�ĩβ������true 
    // while(!Semi.eof()){
	for (int i=0;i<Num_Stu;i++){
		char ch=getchar(); while (ch<'0'||ch>'9') ch=getchar();
    	for (int j=0;j<12;j++) {
			while (ch<'0'||ch>'9') ch=getchar();
			stu[i].ID[j]=ch; ch=getchar();
		}
    	scanf("%lf",&stu[i].score);
    	for(int j=0;j<9;j++) scanf("%lf",&stu[i].sco[j]);
    }
	// printf("!!!!!!!%d\n",Num_Stu);
	// Print_Info(stu,34);
	Print_AllInfo(stu,Num_Stu);
	//	Print_Min(stu,Num_Stu);        //��ͷ�
	//	Print_Max(stu,Num_Stu);        //��߷�
	//	Print_Average(stu,Num_Stu);    //ƽ����
	//	Print_sort(stu,Num_Stu);       //��������
	Print_Question(stu,Num_Stu);   //���С��÷����
	//    Print_Stage(stu,Num_Stu);
	// Semi.close(); 
	return 0;
}

int max_score[9] = {5,5,5,5,5,25,25,20,15};

void Print_Question(Student stu[],int Num_Stu){
	// printf("!!!!!%d\n",Num_Stu);
	// printf("  满分人数   得分人数   得分率(%%)  平均分  满分\n");
	printf("ID\tFullSco\tHaveSco\tRate\tAverage\tRequired\n");
	// cout<<setw(10)<<"题："<<setw(10)<<"满分人数"<<setw(10)<<"得分人数"<<setw(10)<<"得分率(%)"<<setw(10)<<"平均分"<<setw(10)<<"满分"<<endl;
	for (int i=0;i<9;i++){
		double num1=0.0; int num2=0;
		int ak=0,ac=0;
		for (int j=0;j<Num_Stu;j++){
			if (stu[j].sco[i] == max_score[i]) ak++;
			if (stu[j].sco[i] > 0) ac++;
			num1+=stu[j].sco[i]; num2+=max_score[i];
			// printf(" [%d]  [%d]  %.3lf\n",j,i,stu[j].sco[i]);
		}
		// printf("%.2lf\n",num1);
		// printf("!!!!%.3lf\n",stu[35].sco[1]);
		printf("%d\t%d\t%d\t%.2lf\t%.2lf\t%d\n",i+1,ak,ac,num1/num2,num1/Num_Stu,max_score[i]);
		// cout<<setw(10)<<i+1<<setw(10)<<ak<<setw(10)<<ac<<setw(10)<<num1/num2<<setw(10)<<num1/Num_Stu<<setw(10)<<max_score[i]<<endl;
	}
}