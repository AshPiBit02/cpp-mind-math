//Josephus problem direct approach
#include<iostream>
#include<cmath>
using namespace std;
int main()
{
    int n,l;
    cout<<"Enter number of warriors: ";
    cin>>n;
    int a=0;
    while(true)
    {
        if(n>pow(2,a))
        {
            a++;
        }
        else if(n<pow(2,a))
        {
            a--;
            l=n-pow(2,a);
            cout<<"The surviving warrior is at position: "<<(2*l)+1<<endl;
            break;
        }
        else
        {
            cout<<"The surviving warrior is at position: "<<1<<endl;
            break;
        }
    }

}