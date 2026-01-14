//GCD using Euclid's algorithm
#include<iostream>
using namespace std;
int gcdrec(int x,int y)
{
    if(y==0) return x;
    return gcdrec(y,x%y);
}
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
    int lcm(int x,int y)
    {
        return (x*y)/gcdrec(x,y);//lcm=product/gcd;
    }
int main()
{
    cout<<gcd(16,20)<<endl;
    cout<<gcdrec(16,20)<<endl;
    cout<<lcm(16,20)<<endl;
    return 0;
}