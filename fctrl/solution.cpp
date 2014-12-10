//The url of the problem statement is
// http://www.spoj.com/problems/FCTRL/

#include<iostream>
using namespace std;


int main()
{
	int count=0;
	cin >> 	count;
	while(count>0)
	{
		int number;
		cin >> number;
		int div =5;
		int numZeroes = 0;
		while(number >= div)
		{
			number = number/div;
			numZeroes +=number;
		}
		cout<<numZeroes<<endl;
		count--;
	}

	return 0;
}
