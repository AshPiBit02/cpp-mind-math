//This program determines the maximum sum of subarray of size k using sliding window.
#include<iostream>
using namespace std;
int main()
{
    int arr[]={2,3,-8,7,-1,2,3};
    int n=sizeof(arr)/sizeof(arr[0]);
    int k=4,maxSum=INT_MIN,currentSum=0;
    for(int i=0;i<k;i++)
    {
        currentSum+=arr[i];
    }
    for(int i=1;i<n-k+1;i++)
    {
        maxSum=max(maxSum,currentSum);
        currentSum=currentSum+arr[i+k-1]-arr[i-1];
    }
    maxSum=max(maxSum,currentSum);
    cout<<maxSum<<endl;
    return 0;
} // End of main: computes and prints the maximum sum of any contiguous subarray of size k using an O(n) sliding-window approach