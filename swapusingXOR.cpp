//This program uses XOR operation to swap two numbers;
#include<iostream>
using namespace std;
int main()
{
    int a=5,b=2;
    cout<<"Before swapping a = "<<a<<" & b = "<<b<<endl;
    a=a^b; //5^2
    b=a^b; //5^2^2=5
    a=a^b; //5^2^5=2
    cout<<"After swapping a = "<<a<<" & b = "<<b<<endl;
    int x=(10,20,3);
    cout<<x<<endl;
    return 0;
}