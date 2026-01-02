// This program uses brute force approach to find the maximum in each sliding window of size k in the given array.
#include<iostream>
using namespace std;
int main()
{
    int arr[]={2,3,-8,1,-1,2,3};
    int n=sizeof(arr)/sizeof(arr[0]);
    int ansarr[n-2],k=4;
    for(int i=0;i<n-k+1;i++)
    {
        int maxnum=INT_MIN;
        for(int j=i;j<i+k;j++)
        {
            maxnum=max(maxnum,arr[j]);
        }
        ansarr[i]=maxnum;
    }
    for(int i=0;i<n-k+1;i++)
    {
        cout<<ansarr[i]<<" ";
    }
}