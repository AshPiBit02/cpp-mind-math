//This program follow prefix sum approach to find the equilibrium point(sum of left subarray equal to sum of right subarray) of an array.
//Note : This approach works only when all elements are positive or negative or zero.
#include<iostream>
using namespace std;
int main()
{
    int arr[]={5,3,0,3,2};
    int n=sizeof(arr)/sizeof(arr[0]),totalsum=0;
    for(int i=0;i<n;i++)
    {
        totalsum+=arr[i];
    }
    int prefixSum=0;
    bool found=false;
    for(int i=0;i<n;i++)
    {
        if(prefixSum==totalsum-prefixSum-arr[i])//right subarray sum is totalsum-prefixsum-arr[i]
        {
            found=true;
            cout<<"Equilibrium index: "<<i<<endl;
        }
        prefixSum+=arr[i];
    }
    if(!found)
    {
        cout<<"No Equilibrium point!"<<endl;
    }
    return 0;

}