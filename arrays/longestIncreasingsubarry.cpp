//find the longest increasing contiguous subarray.
// In case of multiple subarray having equal longest length, the first longest array will be displayed. 
#include<iostream>
using  namespace std;
int main()
{
    int arr[]={2,4,2,5,7,10,8,9,7};
    int n=sizeof(arr)/sizeof(arr[0]);
    int fresh_start=0,best_start=0,max_len=1;
    for(int i=1;i<n;i++)
    {
        if(arr[i]<arr[i-1])
        {
            fresh_start=i;
        }
        int fresh_len=i-fresh_start+1;
        if(fresh_len>max_len)
        {
            max_len=fresh_len;
            best_start=fresh_start;
        }
    }
    if(max_len>1)
    {
        cout<<"Longest contiguous subarray is : ";
        for(int i=best_start;i<best_start+max_len;i++)
        {
            cout<<arr[i]<<" ";
        }
    }else{
        cout<<"No contiguous increasing array!"<<endl;
    }
    return 0;
}