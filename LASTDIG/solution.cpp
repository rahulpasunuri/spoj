//The problem url is 
//http://www.spoj.com/problems/LASTDIG/
#include<iostream>
#include<stdlib.h>
#include<math.h>
using namespace std;

int main()
{
	int t;	
	string s;
	getline(cin, s);
	t = atoi(s.c_str());
	
	while(t>0)
	{	
		getline(cin, s);
		int index = s.find_first_of(' ');
		unsigned int n1 = atoi(s.substr(0, index).c_str());
		n1 = n1%10; //all other digits are useless for last digit computation..
		s = s.substr(index+1);
		
		unsigned int n2 = atoi(s.c_str());		
		if(n2==0)
		{
			cout<<1;
		}
		else if(n1==0 || n1==1 || n1== 5 || n1==6 )
		{
			cout<<n1;
		}
		else
		{
			n2 = n2%4;		
			cout<<(((int)pow(n1, n2))%10);
		}
		
		cout<<endl;
		t--;
	}		
	return 0;
}
