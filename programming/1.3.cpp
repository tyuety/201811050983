#include<iostream>
using namespace std;
void fun(int a,int b,long*c)
{
*c=(a%10)*1000+(b%10)*100+(a/10)*10+(b/10);
}
int main()
{int a,b;long c;
cout <<"����������λ������,�ո����"<< endl;
cin >> a >> b;
fun(a,b,&c);
cout << c << endl;
}

