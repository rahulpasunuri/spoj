//The problem url is 
//http://www.spoj.com/problems/PRIME1/
#include<iostream>
#include<stdlib.h>
#include<exception>
using namespace std;

int main()
{
	int numSamples;	
	string a; 
	getline(cin, a);
	try 
	{
		numSamples = atoi(a.c_str());
	}
	catch(...)
	{
		 return -1;
	}
	//999900000 1000000000
	while(numSamples>0)
	{		
		string inp;
		getline(cin, inp);
		unsigned int num1, num2;
		//parse the input to get the numbers.
		int spaceIndex = inp.find_first_of(' ');
		if(spaceIndex >= 0)
		{
			try
			{
				num1 = atoi(inp.substr(0, spaceIndex).c_str());
				num2 = atoi(inp.substr(spaceIndex+1).c_str());		
			}
			catch(...)
			{
				numSamples--;
				if(numSamples!=0)
					cout<<endl; //test cases separated by a new line..
				continue;
			}
			unsigned int n = num1;
			if(n==1)
			{
				n++; //1 is neither prime nor composite...
			}
			while(n<=num2)
			{	
				//check whether n is a prime or not..
				int div =2;			
				bool isPrime = true;
				while(div<n) //a number is always divisible by itself (reason for strict inequality)
				{
					unsigned int temp = n/div;			
					if(temp*div == n)
					{
						isPrime = false;
						break;
					}
					else if(temp<div)
					{
						break; //not necessary to look at all the divisors..only looks till the square root of the number in consideration..
					}
					div++;
				}
				if(isPrime)
				{
					cout<<n<<"\n";
				}
				n++;
			}
		}
		numSamples--;
		if(numSamples!=0)
			cout<<endl; //test cases separated by a new line..
	}
	
	return 0;
}
//1000000000
