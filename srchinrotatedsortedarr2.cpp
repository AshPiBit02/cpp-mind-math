//Search in rotated sorted array using while loop
#include<iostream>
using namespace std;
int BinSrchRotSorArr(int* arr,int start,int end,int target)
{
    while(start<=end)
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
                end=mid;
            }
            else
            {
                start=mid+1;
            }
        }
        else{
            if(arr[mid+1]<=target && arr[end]<=target)
            {
                start=mid+1;
            }
            else
            {
                end=mid;
            }
        }
    }
}
int main()
{
    int arr[]={3,4,5,6,7,0,1,2};
    int n=sizeof(arr)/sizeof(arr[0]);
    int target=2;
    cout<<"The target is at index: "<<BinSrchRotSorArr(arr,0,n-1,target);
    return 0;
}