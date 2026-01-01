//This program find the maximun subarray by brute force with slightly optimization
#include<iostream>
// #include<vector>
using namespace std;
int main()
{
    int arr[]={3,-4,5,4,-1,7,-8};
    int n=sizeof(arr)/sizeof(arr[0]);
    int maxsum=INT_MIN;
    for(int st=0;st<n;st++)
    {
        int currentsum=0;
        for(int end=st;end<n;end++)
        {
            currentsum+=arr[end];
            maxsum=max(currentsum,maxsum);
        }
    }
    cout<<"The maximum sum of the subarray is "<<maxsum<<endl;
    return 0;
}