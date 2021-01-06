
#include<bits/stdc++.h>
using namespace std;
char str[110];
stack<int> sInt;     //数字 
stack<char> sChar;   //运算符 
bool iso(char c)   //判读是否为运算符 
{
	if(c=='+' || c=='-' || c=='*' || c=='/' || c=='(' || c==')')
		return true;
	return false;
}
int getRank(char c)   //获取优先级 
{
	if(c=='*' || c=='/')
		return 2;
	else if(c=='+' || c=='-')
		return 1;
	return 0;
}
void calc()       //计算 
{
	int b = sInt.top(); sInt.pop();
	int a = sInt.top(); sInt.pop();
	int c = sChar.top();sChar.pop();
	int d;
	if(c=='+')
		d = a+b;
	else if(c=='-')
		d = a-b;
	else if(c=='*')
		d = a*b;
	else
		d = a/b;
	sInt.push(d);
}
int main()
{
	scanf("%s",str);
	int len = strlen(str);
	for(int i=0;i<len;i++)
	{
		if(iso(str[i]))   //如果不为数字 
		{
			if(str[i]=='(')
				sChar.push(str[i]);
			else if(str[i]==')')      //将括号中的全部算完 
			{
				int c = sChar.top();
				while(c!='(')
				{
					calc();
					c = sChar.top();
				}
				sChar.pop();
			}
			else
			{
				int r = getRank(str[i]);   //获取优先级 
				if(sChar.empty() || r>getRank(sChar.top()))   
					sChar.push(str[i]);
				else                //如果后面的优先级小于等于前面的就把前面的运算算出 
				{
					calc();
					sChar.push(str[i]);
				}
			}
		}
		else    //为数字 
		{
			int t;
			sscanf(str+i,"%d",&t);     
			sInt.push(t);            //将数字入栈 
			for(;!iso(str[i+1]);i++);    //跳到是运算符的地方 
		}
		
	}
	while(!sChar.empty())
	{
		calc();
	}
	printf("%d\n",sInt.top());
}
