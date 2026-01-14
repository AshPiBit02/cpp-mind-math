//Find the subarray sum equal to given target
#include<iostream>
using namespace std;
void subarray(int* arr,int n,int target)
{
    bool found=false;
    int subarr_sum=0,i=0,j=0;
    for(j=0;j<n;j++)
    {
        subarr_sum+=arr[j];
        while(subarr_sum>target && i<j)
        {
            subarr_sum-=arr[i++];
        }
        if(subarr_sum==target)
        {
            cout<<"Subarray sum exists from index "<<i<<" to "<<j<<endl;
            found=true;
        }
    }
    if(!found)
    {
    cout<<"Subarray sum doesn't exists!"<<endl;
    }
}
int main()
{
    int arr[]={1,3,4,7,12,16,17,19};
    int n=sizeof(arr)/sizeof(arr[0]),target=19;
    subarray(arr,n,target);
    return 0;
}