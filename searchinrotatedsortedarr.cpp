//Search in rotated sorted array using recursion
#include<iostream>
using namespace std;
int BinsrchElement(int* arr,int start,int end,int target)
{
    int mid=start+(end-start)/2;
    if(arr[mid]==target)
    {
        return mid;
    }
    else if(arr[start]<arr[mid])
    {
        if(arr[start]<=target && arr[mid]>=target)
        {
        return BinsrchElement(arr,start,mid,target);
        }
        else
        {
            return BinsrchElement(arr,mid+1,end,target);
        }
    }
    else
    {
        if(arr[mid+1]<=target && arr[end]>=target)
        {
            return BinsrchElement(arr,mid+1,end,target);
        }
        else
        {
            return BinsrchElement(arr,start,mid-1,target);
        }
    }

}
int main()
{
    int arr[]={3,4,5,6,7,8,1,2};
    int n=sizeof(arr)/sizeof(arr[0]);
    int target=5;
    cout<<BinsrchElement(arr,0,n-1,target);
    return 0;
}