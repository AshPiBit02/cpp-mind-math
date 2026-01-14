//This program check if the input number is power of 2 or not without using modulus operator.
#include<iostream>
using namespace std;
int main()
{
    int x;
    cout<<"Enter a number to check if it is power of 2 or not: ";
    cin>>x;
    if((x&(x-1))==0)
    {
        cout<<x<<" is power of 2."<<endl;
    }
    else
    {
        cout<<x<<" isn't power of 2."<<endl;
    }
    return 0;
}