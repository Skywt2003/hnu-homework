#include<cstdio>
#include<cstring>
#include<iostream>

using namespace std;

int main()
{
int n;
cin >> n;
switch(n++)
{
    case 1:
    case 2: cout << '1';
    case 3:
    case 4: cout << '2'; break;
    default: cout << '3';
}
}
