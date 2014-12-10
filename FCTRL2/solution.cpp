//The problem url is 
//http://www.spoj.com/problems/FCTRL2/
#include<iostream>
using namespace std;


//main idea of the program
/*
a number like 100! is too big and cannot be fit in 32 or 64 bits undigned integers.
so we represent a big number in an array format.
for example, a number like 5432 is saved in an array {2,3,4,5,0,0,0,0,0,0,0,0}
(the least significant bit is stored at 0th index)

Computing Factorial:
while(num>1)
{
	//multiply each digit by the number.
	//start from the left, and do a %10 to get the value that must be at that positon 
	//do a[i+1] = a[i]/10; this takes care of the carry over..
	//at every stage, maintain the index of the highest significant bit, to optimize it properly..
	num--;
}

*/


int main()
{
	int numSamples = 0;
	cin>>numSamples;
	while(numSamples>0)
	{
		unsigned int a[200] = {0};
		a[0]=1; //init..
		unsigned int num =0;
		cin >> num;
		int maxIndex = 0;
		while(num>1)
		{
			int i =0;
			while(i<=maxIndex)
			{
				a[i]*=num;				
				i++;
			}
			i=0;
			while(i<maxIndex)
			{
				if(a[i]>=10)
				{
					int temp = a[i]/10;
					a[i] = a[i]%10;
					a[i+1] += temp;
				}
				i++;
			}			
			//here i = max index..
			int temp = 0;
			while(a[i]>10)
			{
				maxIndex+=1;
				int temp = a[i]/10;
				a[i] = a[i]%10;
				a[i+1] += temp;
				i++;					
			}		
			num--;			
		}
		int j=0;
		while(j<=maxIndex)
		{
			cout<<a[maxIndex-j];
			j++;
		}
		//cout<<"what???";
		cout<<endl;
		numSamples--;
	}
	
	return 0;
}
