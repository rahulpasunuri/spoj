//The problem url is 
//http://www.spoj.com/problems/NSTEPS/

#include<iostream>
#include<stdlib.h>
using namespace std;

int main()
{
	string s;
	getline(cin, s);
	int numSamples = atoi(s.c_str());
	
	while(numSamples>0)
	{
		string c;
		getline(cin, c);
		int index = c.find_first_of(' ');
		int num1, num2;
		num1 = atoi(c.substr(0,index).c_str());
		num2 = atoi(c.substr(index+1).c_str());
		if(num1==num2 || num2+2==num1)
		{
			if(num1%2 ==0) //case where num1 is even..
			{
				cout<<(num1+num2);
			}
			else if(num2%2==1) //both are odd..
			{
				cout<<(num1+num2-1);
			}
		}
		else
		{
			cout<<"No Number";
		}
		cout<<endl;
		numSamples--;
	}
	return 0;
}
