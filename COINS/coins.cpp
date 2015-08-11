#include<bits/stdc++.h> 
#include<iostream>
#include<map>
using namespace std;


map<long long,long long> maxValue;
long long getMaxValue(long long coinValue)
{
    if( coinValue!=0 && !maxValue[coinValue])
    {
        long long val = getMaxValue(coinValue/2) + getMaxValue(coinValue/3) + getMaxValue(coinValue/4);
        if(val > coinValue)
        {
            maxValue[coinValue] = val;
        }
        else
        {
            maxValue[coinValue] = coinValue;
        }
    }
    return maxValue[coinValue];
}


int main()
{
    maxValue[0] = 0;
    long long num;
    while(cin>>num)
    {
        cout<<getMaxValue(num)<<endl;
    }
	return 0;
}
