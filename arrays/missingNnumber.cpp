//Find the missing number from 1 to n;
#include<iostream>
using namespace std;
int main()
{
    int arr[]={1,2,3,5,6,7,8,9};
    int n=sizeof(arr)/sizeof(arr[0]);
    int arr_sum=0;
    for(int i=0;i<n;i++)
    {
        arr_sum+=arr[i];
    }
    int x=n+1;//number of element including the missing one
    int total_sum=(x*(x+1))/2;
    cout<<"The missing number is "<<total_sum-arr_sum<<endl;
    return 0;
}