
#include<bits/stdc++.h>
using namespace std;
char str[110];
stack<int> sInt;     //���� 
stack<char> sChar;   //����� 
bool iso(char c)   //�ж��Ƿ�Ϊ����� 
{
	if(c=='+' || c=='-' || c=='*' || c=='/' || c=='(' || c==')')
		return true;
	return false;
}
int getRank(char c)   //��ȡ���ȼ� 
{
	if(c=='*' || c=='/')
		return 2;
	else if(c=='+' || c=='-')
		return 1;
	return 0;
}
void calc()       //���� 
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
		if(iso(str[i]))   //�����Ϊ���� 
		{
			if(str[i]=='(')
				sChar.push(str[i]);
			else if(str[i]==')')      //�������е�ȫ������ 
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
				int r = getRank(str[i]);   //��ȡ���ȼ� 
				if(sChar.empty() || r>getRank(sChar.top()))   
					sChar.push(str[i]);
				else                //�����������ȼ�С�ڵ���ǰ��ľͰ�ǰ���������� 
				{
					calc();
					sChar.push(str[i]);
				}
			}
		}
		else    //Ϊ���� 
		{
			int t;
			sscanf(str+i,"%d",&t);     
			sInt.push(t);            //��������ջ 
			for(;!iso(str[i+1]);i++);    //������������ĵط� 
		}
		
	}
	while(!sChar.empty())
	{
		calc();
	}
	printf("%d\n",sInt.top());
}
