//The problem url is 
//http://www.spoj.com/problems/SAMER08F/
#include<iostream>
using namespace std;

int main()
{
	int numSides = 0;
	cin>>numSides;
	
	while(numSides!=0)
	{		
		int numSquares = 0;
		for(int i=0; i<numSides ;i++)
		{
			for(int j=0; j<=numSides;j++)
			{
				int size =1;
				while(size<=numSides)
				{
					if(i+size<=numSides && j+size<=numSides)
					{
						numSquares+=1;
					}
					size++;
				}
				//cout<<"i is "<<i<<" j is "<<j<<endl;				
			}
		}			
		cout<<numSquares<<endl;
		cin>>numSides;
	}		
		
	return 0;
}
