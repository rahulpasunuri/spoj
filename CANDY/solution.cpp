//The problem url is 
//http://www.spoj.com/problems/CANDY/
#include<iostream>
using namespace std;

int main()
{
	int numCandies = 0;
	cin>>numCandies;
	
	while(numCandies!=-1)
	{		
		int* c = new int[numCandies];
		int sum=0;
		for(int i=0; i <numCandies;i++)
		{
			cin>>c[i];
			sum+=c[i];
		}
		int correct = sum/numCandies;
		if(sum!=numCandies*correct)
		{
			cout<<-1<<"\n";
		}
		else
		{
			int exchange=0;
			for(int i=0; i <numCandies;i++)
			{
				if(c[i]>correct)
				{
					exchange+=(c[i]-correct);
				}				
			}
			cout<<exchange<<"\n";			
		}
		delete[] c;		 
		cin>>numCandies;
	}		
		
	return 0;
}
