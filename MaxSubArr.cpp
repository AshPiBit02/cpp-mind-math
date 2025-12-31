//This program finds the subarray of two elements with largest sum.
#include<iostream>
using namespace std;
int main()
{
    int arr[]={-3,3,3,-5,6,3,2};
    int n=sizeof(arr)/sizeof(arr[0]);
    int currentSum,maxsum=0,idx1,idx2;
    for(int i=0;i<n-2;i++)
    {
        currentSum=arr[i]+arr[i+1];
        if(currentSum>maxsum)
        {
            maxsum=currentSum;
            idx1=i,idx2=i+1;
        }
    }
    cout<<"The Subarray with largest sum is ["<<arr[idx1]<<","<<arr[idx2]<<"]"<<endl;
    return 0;
}