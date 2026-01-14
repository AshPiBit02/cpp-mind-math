//Reverse number
#include<iostream>
using namespace std;
int revnum(int num)
{
    int rnum=0;
    while(num>0)
    {
        int digit=num%10;
        if(rnum*10>INT_MAX || rnum<INT_MIN/10)//handles range if the reverse number is going to exceed or cross the min int value
        
        {
            return 0;
        }
        rnum=(rnum*10)+digit;
        num/=10;
    }
    return rnum;
}
int main()
{
    cout<<revnum(1376)<<endl;
}