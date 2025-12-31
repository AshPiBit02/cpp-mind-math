#include<iostream>
using namespace std;
int main()
{
    int a[]={2,11,15,5,7};

    int val=26;
    int i=0,j=0;
    while(j<=4)
    {
        if(a[i]<val)
        {
            j++;
        }
        else
        {
            i++;
        }
        if(a[i]+a[j]==val)
        {
            cout<<"The numbers are at index: "<<i<<" & "<<j<<endl;
            break;
        }
        else{
            i++;
        }
    }
    return 0;
}