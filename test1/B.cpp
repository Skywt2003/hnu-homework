#include  <iostream> 
using  namespace  std; 
int  insertsort(int*  ,  int);    ////函数原型声明 
int  main() 
{ 
        int  n; 
        cin  >>  n; 
        int  *a=  new  int[n]; 
        for(int  i  =  0;  i  <  n;  i++)       
              {                cin>>a[i];              } 
                cout  <<  insertsort(a,n);      /////调用插入排序函数，返回插入排序的数据两两交换总次数 
                delete[]  a;       
        return  0; 
} 
int  insertsort(int a[], int n)    ////////请参照函数原型给出形参列表 
{ 
          int  cnt=0;    ///////两两交换次数的计数变量 
///////请给出函数的具体实现 
        if (n==1) return 0;
        for (int i=1;i<n;i++){
                if (a[i]>=a[i-1]) continue;
                int ins=-1;
                for (int j=i-1;j>=0;j--) if (a[j]<=a[i] && a[i]<=a[j+1]) {ins=j+1;break;}
                if (a[i]<a[0]) ins=0;
                for (int j=i;j>ins;j--) swap(a[j],a[j-1]),cnt++;
        }
        return cnt;
}