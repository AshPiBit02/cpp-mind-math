/*Quick sort by median of three
Median-of-three reduces the chance of picking a bad pivot, especially for:
Already sorted arrays
Reverse sorted arrays
Nearly sorted arrays*/
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int medianofthree(vector<int>&arr,int start,int end)
{
    int mid=start+(end-start)/2;
    if(arr[start]>arr[mid])
    {
        swap(arr[start],arr[mid]);
    }
    if(arr[mid]>arr[end])
    {
        swap(arr[mid],arr[end]);
    }
    if(arr[start]>arr[end])
    {
        swap(arr[start],arr[end]);
    }
    return mid;
}
int partition(vector<int>&arr,int start,int end)
{
        int pivotidx=medianofthree(arr,start,end);
        swap(arr[pivotidx],arr[end]);
        int idx=start-1,pivot=arr[end],i=start;
        while(i<end)
        {
            if(arr[i]<=pivot)
            {
                swap(arr[++idx],arr[i]);
            }
            i++;
        }
        swap(arr[idx+1],arr[end]);
        return idx+1;
}
void quicksort(vector<int>&arr,int start,int end)
{
    if(start<end)
    {
        int pivot=partition(arr,start,end);
        quicksort(arr,start,pivot-1);
        quicksort(arr,pivot+1,end);
    }
}
int main()
{
    vector<int>arr={22,10,18,11,14,19,23,17,18};
    quicksort(arr,0,arr.size()-1);
    for(auto i: arr)
    {
        cout<<i<<" ";
    }
    cout<<endl;
    return 0;
}