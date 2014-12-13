//The problem url is 
//http://www.spoj.com/problems/TOANDFRO/
#include<iostream>
using namespace std;

int main()
{
	int numColumn = 0;	
	cin>>numColumn;
	while(numColumn!=0)
	{		
		char a[210];
		cin>>a;
		int index=0;
		int len=0;
		while(a[len]!='\0')
		{
			len++;
		}
		int row=0;		
		int totalBlocks = len/numColumn;
		while(index<numColumn)
		{
			bool isReverse = false;
			for(int i=0; i<totalBlocks; i++)
			{			
				if(!isReverse)
				{
					cout<<a[index+i*numColumn];	
					isReverse = true;		
				}
				else
				{
					cout<<a[i*numColumn+numColumn-index-1];
					isReverse = false;
				}
			}						
			index+=1;			
		}
		cout<<endl;
		cin>>numColumn;
	}		
		
	return 0;
}
