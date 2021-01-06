#include<iostream>
using namespace std;
void fun(int &a,int &b)
{
	int c,c1,c2,c3,c4;
	c1=a%10;
    c2=b%10;
    c3=a/10;
    c4=b/10;
    c=c1*1000+c2*100+c3*10+c4;
    cout << c << endl;
}
int main()
{
	int a,b;
	cout <<"输入两个两位正整数,空格隔开"<< endl;
	cin >> a >> b;
	fun(a,b);

}

