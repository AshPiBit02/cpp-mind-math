//To count how many ways an array can split into two non-empty parts such that the sum of the left part 
//is strictly greater than the sum of the right part
#include<iostream>
using namespace std;
int main()
{
    int arr[]={10,4,-8,7,3,6};
    int n=sizeof(arr)/sizeof(arr[0]);
    int totalSum=0,prefixSum=0,count=0;
    for(int i=0;i<n;i++)
    {
        totalSum+=arr[i];
    }
    for(int i=0;i<n-1;i++)
    {
        prefixSum+=arr[i];
        if(prefixSum*2>totalSum)
        {
            count++;
        }
    }
    cout<<"The number of valid split is "<<count<<endl;
    return 0;

}