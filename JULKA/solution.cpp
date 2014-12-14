//The problem url is 
//http://www.spoj.com/problems/JULKA/
#include<iostream>
#include<stdlib.h>
using namespace std;

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
		cout<<tLength<<endl;

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
		}
		for(int i=eLength; i<tLength; i++)
		{
			sum[i] = total[i] +carry;
			if(sum[i]>9)
			{
				sum[i]-=10;
				carry=1;
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
		}
		for(int i=eLength; i<tLength; i++)
		{
			diff[i] = total[i]-carry;
			if(diff[i]<0)
			{
				diff[i]+=10;
				carry=1;
			}
		}		
		
		for(int i=tLength-1; i>=0;i--)
		{
			cout<<diff[i];
		}
		cout<<endl;
		testCases--;
	}		
		
	return 0;
}
