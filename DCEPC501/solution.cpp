#include<bits/stdc++.h> 
#include<iostream>
#include<vector>
#include<string>
using namespace std;

/**
*http://www.spoj.com/problems/DCEPC501/
*/

long max_three(long a, long b, long c)
{
    return max(a, max(b, c));
}

long* maxValue;
long getMaxValueSubArray(int start, vector<long> seq)
{
    if(start>=seq.size())
    {
        return 0;
    }
    else if(maxValue[start] != 0)
    {
        return maxValue[start];
    }
    
    long p3=0, p2=0;
    maxValue[start] = seq[start];
    if(start+2<seq.size())
    {
        p3 = getMaxValueSubArray(start+6,seq) + seq[start+1]+seq[start+2];
    }

    if(start+1<seq.size())
    {
        p2 = getMaxValueSubArray(start+4,seq) + seq[start+1];
    }

    long p1 = getMaxValueSubArray(start+2,seq);
    
    maxValue[start] += max_three(p1, p2, p3);
    return maxValue[start];
}

long getMaxSequence(vector<long> seq)
{
    return getMaxValueSubArray(0, seq);
}


int main()
{
    string line;
    getline(cin, line);
    int numTestCases = atoi(line.c_str());
    while(numTestCases>0)
    {
        vector<long> sequence;
        getline(cin, line);
        int size = atoi(line.c_str());
        getline(cin, line);
        maxValue = new long[size];
        for(int i=0; i<size; i++)
        {
            maxValue[i] = 0;
        }
        while(size>0)
        {
            int index = line.find_first_of(' ');
            sequence.push_back(atol(line.substr(0, index).c_str()));
            line = line.substr(index+1);
            size--;
        }
        cout<<getMaxSequence(sequence)<<endl;
        delete[] maxValue;
        numTestCases--;
    }
	return 0;
}
