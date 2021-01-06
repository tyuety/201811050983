#include<iostream>
using namespace std;
int main()
{
int a, b, c;
cout <<"输入两个两位正整数,空格隔开"<< endl;
cin >> a >> b;
//对a和b进行分解。
c = ((a % 10) * 1000 )+ ((b % 10) * 100 )+ ((a / 10) * 10) + (b / 10);
cout << c << endl;
system("pause");
return 1;
}

