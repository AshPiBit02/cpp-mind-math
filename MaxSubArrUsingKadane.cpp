//This program find the maximum subarray sum using kadane's algorithm
#include<iostream>
using namespace std;
int main()
{
    int arr[]={2,3,-8,7,-1,2,3};
    int n=sizeof(arr)/sizeof(arr[0]);
    int maxsum=INT_MIN,currentsum=0;
    for(int i=0;i<n;i++)
    {
        currentsum+=arr[i];
        maxsum=max(maxsum,currentsum);
        if(currentsum<0)
        {
            currentsum=0;
        }
    }
    cout<<"The maximum subarray sum is "<<maxsum<<endl;
    return 0;
}