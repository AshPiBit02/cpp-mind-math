#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
bool ispossible(vector<int>&arr,int max_distance,int no_cows,int n)
{
    int cow_count=1,last_stall_pos=arr[0];
    for(int i=1;i<n;i++)
    {
        if((last_stall_pos+max_distance)<=arr[i])
        {
            cow_count++;
            last_stall_pos=arr[i];
        }
    }
    return cow_count<no_cows?false:true;
}
int get_distance(vector<int>&arr,int n,int  no_cows)
{
    if(no_cows>n) return -1;
    sort(arr.begin(),arr.end());
    int start=1,end=arr[n-1]-arr[0],ans=-1;//start is min and end is max position
    while(start<=end)
    {
        int mid=start+(end-start)/2;
        if(ispossible(arr,mid,no_cows,n))
        {
            ans=mid;
            start=mid+1;
        }
        else
        {
            end=mid-1;
        }
    }
    return ans;
}
int main()
{
    vector<int>arr={1,2,8,4,9};
    int n=arr.size();
    int no_cows=3;
    cout<<get_distance(arr,n,no_cows);
    return 0;
}
