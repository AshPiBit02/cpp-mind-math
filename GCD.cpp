//GCD using Euclid's algorithm
#include<iostream>
using namespace std;
int gcd(int x,int y)
{
    while(x>0 && y>0)
    {
        if(x>y)
        {
            x%=y;
        }
        else
        {
            y%=x;
        }
    }
    return x==0?y:x;
    }
int main()
{
    cout<<gcd(16,20)<<endl;
    return 0;
}