#include<iostream>
#include<vector>
using namespace std;
bool isvalid(vector<int>&arr,int total_painter,int max_paint_time)
{
    int count_painter=1,n=arr.size(),paint_time=0;
    for(int i=0;i<n;i++)
    {
        if(paint_time+arr[i]>max_paint_time)
        {
            count_painter++;
            paint_time=arr[i];
        }else{
            paint_time+=arr[i];
        }
    }
    return count_painter>total_painter?false:true;
}
int min_time_to_paint(vector<int>&arr,int total_painter)
{
    int n=arr.size();
    if(total_painter>n) return -1;
    int max_time=0,min_time=INT_MIN;
    for(int i=0;i<n;i++)
    {
        max_time+=arr[i];
        min_time=max(min_time,arr[i]);
    }
    int start=min_time,end=max_time,ans=-1;
    while(start<=end)
    {
        int mid=start+(end-start)/2;
        if(isvalid(arr,total_painter,mid))
        {
            ans=mid;
            end=mid-1;
        }else
        {
            start=mid+1;
        }
    }
    return ans;
}
int main()
{
    vector<int>arr={40,30,10,20};
    int total_painter=2;
    cout<<min_time_to_paint(arr,total_painter);
    return 0;
}