//The problem url is 
//http://www.spoj.com/problems/ACPC10A/
#include<iostream>
#include<stdlib.h>
using namespace std;

int main()
{
	string inp;
	getline(cin, inp);	
	while(inp!="0 0 0")
	{		
		int n1,n2,n3;
		//fetch first number..
		int index = inp.find_first_of(' ');
		n1 = atoi(inp.substr(0, index).c_str());
		inp = inp.substr(index+1);
		
		//fetch 2nd number..
		index = inp.find_first_of(' ');
		n2 =  atoi(inp.substr(0, index).c_str());
		
		//fetch third nuumber..
		n3 = atoi(inp.substr(index+1).c_str());

		if(n3-n2 == n2-n1)
		{
			cout<<"AP "<<(n3+n2-n1)<<endl;
		}
		else
		{
			cout<<"GP "<<(n3*n3)/n2<<endl;
		}
		
		//get next input..
		getline(cin, inp);				
	}		
		
	return 0;
}
