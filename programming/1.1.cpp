#include<iostream>
using namespace std;
int main()
{
int a, b, c;
cout <<"����������λ������,�ո����"<< endl;
cin >> a >> b;
//��a��b���зֽ⡣
c = ((a % 10) * 1000 )+ ((b % 10) * 100 )+ ((a / 10) * 10) + (b / 10);
cout << c << endl;
system("pause");
return 1;
}

