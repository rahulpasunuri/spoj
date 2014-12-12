//The problem url is 
//http://www.spoj.com/problems/ONP/
#include<iostream>
using namespace std;

class Stack
{
	private:
		char a[400];
		int length;
		
	public:
		Stack()
		{
			length = 0;
		}
		void push(char alp)
		{
			a[length] = alp;
			length++;
		}
		char pop()
		{
			length--;
			return a[length];
		} 
};

int main()
{
	int numSamples = 0;
	cin>>numSamples;
	
	while(numSamples>0)
	{
		char exp[400];
		cin >> exp;
		Stack st;
		for(int i=0; exp[i]!='\0';i++)		
		{
			if ( exp[i] ==  '+' || exp[i] ==  '-' || exp[i] ==  '*' || exp[i] ==  '/' || exp[i] ==  '^')
			{
				st.push(exp[i]);
			}
			else if(exp[i] == ')')
			{
				cout<<st.pop();
			}
			else if(exp[i]!='(')
			{
				cout<<exp[i];
			}
		}
		cout<<endl;
		numSamples--;
	}
	return 0;
}
