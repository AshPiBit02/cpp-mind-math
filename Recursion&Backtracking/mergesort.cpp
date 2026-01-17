//Merge sorting using recursion and backtracking
#include<iostream>
#include<vector>
using namespace std;
void merge(vector<int>&arr,int start,int mid,int end)
{
    vector<int>temp;
    int i=start,j=mid+1;
    while(i<=mid && j<=end)
    {
        if(arr[i]<arr[j])
        {
            temp.push_back(arr[i++]);
        }
        else
        {
            temp.push_back(arr[j++]);
        }
    }
    while(i<=mid)
    {
        temp.push_back(arr[i++]);
    }
    while(j<=end)
    {
        temp.push_back(arr[j++]);
    }
    for(int idx=0;idx<temp.size();idx++)
    {
        arr[idx+start]=temp[idx];
    }
}
void mergesort(vector<int>&arr,int start,int end)
{
    if(start<end)
    {
        int mid=start+(end-start)/2;
        mergesort(arr,start,mid);//left half
        mergesort(arr,mid+1,end);//right half
        merge(arr,start,mid,end);
    }
}
int main()
{
    vector<int>arr={12,32,11,9,32,7,15,3};
    mergesort(arr,0,arr.size()-1);
    for(auto i:arr)
    {
        cout<<i<<" ";
    }
    return 0;
}