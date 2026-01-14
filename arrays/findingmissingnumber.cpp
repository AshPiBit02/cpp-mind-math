//finding the one missing number from the array of natural numbers
#include<iostream>
using namespace std;
int main()
{
    int arr[]={1,2,3,4,5,6,8};
    int n=sizeof(arr)/sizeof(arr[0]);
    //Using Guass formula
    int totalsum=0,x=n+1;// x represent the total number of natural numbers
    for(int i=0;i<n;i++)
    {
        totalsum+=arr[i];
    }
    cout<<"Missing natural number is "<<(x*(x+1)/2)-totalsum<<endl;
    //using XOR 
    int allXOR=0,arrXOR=0;
    for(int i=0;i<n;i++)
    {
        arrXOR^=arr[i];
    }
    for(int i=1;i<=x;i++)
    {
        allXOR^=i;
    }
    cout<<(arrXOR^allXOR)<<endl;
    return 0;
}