//The problem url is 
//http://www.spoj.com/problems/AE00/
#include<iostream>
#include<stdlib.h>
#include<math.h>
using namespace std;

int main()
{
	int numSquares;
	cin>>numSquares;	

	int count=0;
	for(int i=0;i<numSquares;i++)
	{
		for(int j=i; (i+1)*(j+1)<=numSquares; j++)
		{
			count++;
		}
	}
	cout<<count<<endl;
	return 0;
}
