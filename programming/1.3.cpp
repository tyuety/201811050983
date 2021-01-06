#include<iostream>
using namespace std;
void fun(int a,int b,long*c)
{
*c=(a%10)*1000+(b%10)*100+(a/10)*10+(b/10);
}
int main()
{int a,b;long c;
cout <<"输入两个两位正整数,空格隔开"<< endl;
cin >> a >> b;
fun(a,b,&c);
cout << c << endl;
}

