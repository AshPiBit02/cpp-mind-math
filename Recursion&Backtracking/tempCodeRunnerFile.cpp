//Inversion count
#include<iostream>
#include<vector>
using namespace std;
int merge(vector<int>&arr,int start,int mid,int end)
{
    int i=start,j=mid+1;
    int invcount=0;
    vector<int>temp;
    while(i<=mid && j<=end)
    {
        if(arr[i]<=arr[j])
        {
            temp.push_back(arr[i++]);
        }else
        {
            temp.push_back(arr[j++]);
            invcount+=(mid-i+1);
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
    for(int k=0;k<temp.size();k++)
    {
        arr[k+start]=temp[k];
    }
    return invcount;
}
int mergesort(vector<int>&arr,int start,int end)
{
    if(start<end)
    {
        int mid=start+(end-start)/2;
        int inversionleft=mergesort(arr,start,mid);
        int inversionright=mergesort(arr,mid+1,end);
        int invcount=merge(arr,start,mid,end);
        return inversionleft+inversionright+invcount;
    }
    return 0;
}
int main()
{
    vector<int>arr={6,3,5,2,7};
    cout<<mergesort(arr,0,arr.size()-1);
    for(auto i:arr)
    {
        cout<<i<<" ";
    }
    cout<<endl;
    return 0;
}