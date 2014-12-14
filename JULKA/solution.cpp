//The problem url is 
//http://www.spoj.com/problems/JULKA/
#include<iostream>
#include<stdlib.h>
using namespace std;

void divideByTwo(int* num, int len)
{
	int carry=0;
	bool nonZeroSeen = false;	
	for(int i=len-1; i>=0; i--)
	{
		int n = (num[i]+10*carry)/2;
		if(n*2 != num[i]+10*carry)
		{
			carry=1;
		}
		else
		{
			carry=0;
		}
		if(!nonZeroSeen)
		{
			if(n!=0)
			{
				cout<<n;
				nonZeroSeen = true;
			}
		}
		else
		{
			cout<<n;
		}
	}
	cout<<endl;
}

int main()
{
	int testCases = 10;	
	while(testCases>0)
	{	
		string totalString;
		string extraString;
		
		getline(cin, totalString);	
		getline(cin, extraString);
		
		int tLength = totalString.length();
		int eLength = extraString.length();
		
		int* total = new int[tLength];
		int* extra = new int[eLength];

		//get the total into a array..						
		for(int i=0; i<tLength; i++)
		{
			char c[1];
			c[0] = totalString[tLength-1-i];
			total[i] = atoi(c);
		}
		
		//get the extra into a array..						
		for(int i=0; i<eLength; i++)
		{
			char c[1];
			c[0] = extraString[eLength-1-i];
			extra[i] = atoi(c);
		}


		//add two numbers..
		int carry = 0;
		int* sum = new int[tLength+1];
		for(int i=0; i<eLength; i++)
		{
			sum[i] = total[i]+extra[i]+carry;
			if(sum[i]>9)
			{
				sum[i]-=10;
				carry=1;
			}
			else
			{
				carry=0;
			}
		}
		for(int i=eLength; i<tLength; i++)
		{
			sum[i] = total[i] +carry;
			if(sum[i]>9)
			{
				sum[i]-=10;
				carry=1;
			}
			else
			{
				carry=0;
			}
		}		
		
		sum[tLength] = carry;
		
		//now compute the difference of the large numbers..
		int* diff = new int[tLength];
		carry = 0;
		for(int i=0; i<eLength; i++)
		{
			diff[i] = total[i]-extra[i]-carry;
			if(diff[i]<0)
			{
				diff[i]+=10;
				carry=1;
			}
			else
			{
				carry=0;
			}
		}
		for(int i=eLength; i<tLength; i++)
		{
			diff[i] = total[i]-carry;
			if(diff[i]<0)
			{
				diff[i]+=10;
				carry=1;
			}
			else
			{
				carry=0;
			}
		}						
		


		divideByTwo(sum, tLength+1);
		divideByTwo(diff, tLength);
				
		//delete all the variables..
		delete[] total;
		delete[] extra;
		delete[] diff;
		delete[] sum;		
		testCases--;
	}		
		
	return 0;
}
