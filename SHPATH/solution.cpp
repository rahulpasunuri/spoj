//The problem url is 
//http://www.spoj.com/problems/SHPATH/
#include<iostream>
#include<vector>
#include<stdlib.h>
using namespace std;

class neighbour
{
	public:
		int index;
		int weight;
};

class node
{
	public:
		string name;
		vector<neighbour> adjNodes;
};

int main()
{
	int numTests;
	string temp;
	getline(cin, temp);
	numTests = atoi(temp.c_str());		
	while(numTests>0)
	{
		int numCities;
		getline(cin, temp);
		numCities = atoi(temp.c_str());
		
		vector<node> graph; // will store the adgacency list...
		
		for(int i=0; i<numCities;i++)
		{			
			node curr;
			getline(cin,curr.name); //get the name of the city.
			string np;
			getline(cin, np);
			int n = atoi(np.c_str());			
			for(int j=0; j<n;j++)
			{			
				getline(cin, temp);
				int index = temp.find_first_of(' ');
				neighbour n1;
				n1.index = atoi(temp.substr(0, index).c_str());
				n1.weight = atoi(temp.substr(index+1).c_str());
				curr.adjNodes.push_back(n1);
			}		
			graph.push_back(curr);			
		}
		getline(cin, temp);
		int testCases = atoi(temp.c_str());
		for(int i=0; i<testCases; i++)
		{
			getline(cin, temp);
			int index = temp.find_first_of(' ');
			string c1 = temp.substr(0, index);
			string c2 = temp.substr(index+1);
			cout<<c1<<" "<<c2<<endl;
		}
		numTests--;
	}
	return 0;
}
