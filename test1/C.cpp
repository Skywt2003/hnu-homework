#include  <iostream> 
using  namespace  std; 
int  binsear(int*  ,  int  ,  int  ,  int  );    ////函数原型声明 
int  main() 
{ 
        int  n; 
        cin  >>  n; 
        int  *a=  new  int[n]; 
        for(int  i  =  0;  i  <  n;  i++)       
              {                cin>>a[i];              } 
        int  num=0; 
                cin>>num; 
                cout  <<  binsear(a,0,n-1,num);      /////调用二分查找函数，返回比较次数 
        return  0; 
} 
int  binsear(int a[], int l, int r, int num)    ////////请参照函数原型给出形参列表 
{ 
	static int cnt=0;    //////比较次数声明为静态变量 
    int  mid=0;      /////////二分查找的中值 
	while (l<=r){
		cnt++;
		mid=((r-l)>>1)+l;
		if (num == a[mid]) break;
		if (num < a[mid]) r=mid-1;
		else l=mid+1;
	}
	return cnt;
}