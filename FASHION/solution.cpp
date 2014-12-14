//The problem url is 
//http://www.spoj.com/problems/FASHION/
#include<iostream>
#include<vector>
#include<algorithm>
#include<stdlib.h>
using namespace std;

int main()
{
	string s;
	int testCases = 0;
	getline(cin,s);
	testCases = atoi(s.c_str());
	
	while(testCases>0)
	{		
		getline(cin,s);		
		int count = atoi(s.c_str());
		
		vector<int> men;
		vector<int> women;
		
		string menString,womenString;
		getline(cin,menString);
		getline(cin,womenString);
		
		for(int i=0;i<count;i++)
		{
			//get men's hotness
			int i1 = menString.find_first_of(' ');
			men.push_back(atoi(menString.substr(0, i1).c_str()));
			menString = menString.substr(i1+1);

			//get women's hotness
			i1 = womenString.find_first_of(' ');
			women.push_back(atoi(womenString.substr(0, i1).c_str()));
			womenString = womenString.substr(i1+1);
		}
		sort(men.begin(), men.end());
		sort(women.begin(), women.end());
		int sum=0;
		for(int i=0;i<count;i++)
		{
			sum+=(men[i]*women[i]);
		}
		cout<<sum<<endl;
		testCases--;
	}		
		
	return 0;
}



