#include<iostream>
using namespace std;

/**
*http://www.spoj.com/problems/EIGHTS/
*/

long long getNextFatLady(long long count)
{
    return (10*(19+25*(count-1))+2);
}

int main()
{
    int numTestCases;
    cin >> numTestCases;
    long long count;
    while (numTestCases > 0)
    {
        cin >> count;
        cout<<getNextFatLady(count)<<endl;
        numTestCases--;
    }
    return 0;
}
