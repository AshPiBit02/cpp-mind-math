//This program find the maximum profit by buying and selling the stock(array is the stock prices on consecutive days)
#include<iostream>
using namespace std;
int main()
{
    int min_buy=INT_MAX;
    int prices[]={7,8,5,1,6,11};
    int max_profit=0,n=sizeof(prices)/sizeof(prices[0]);
    for(int day=0;day<n;day++)//indexes are the consecutive days
    {
        if(prices[day]<min_buy)
        {
            min_buy=prices[day];
        }
        else
        {
            max_profit=max(max_profit,prices[day] - min_buy);
        }
    }
    cout<<"Maximum profit after selling the stock : "<<max_profit<<endl;
    return 0;
}