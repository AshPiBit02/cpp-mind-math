//GCD using Euclid's algorithm
#include<iostream>
using namespace std;
int gcd(int x,int y)
{
    if(x==0 || y==0)
    {
        if(x==0)
        {
            return y;
        }
        else
        {
            return x;
        }
    }else{

        if(x>y)
        {
            return gcd(x-y,y);
        }
        else //if y>=x 
        {
            return gcd(x,y-x);
        }
    }
    }
int main()
{
    int x=66,y=100;
    cout<<gcd(x,y);
    return 0;
}