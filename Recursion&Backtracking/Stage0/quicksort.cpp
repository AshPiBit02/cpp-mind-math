//Quick sort (assuming last element as pivot)
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int partition(vector<int>&arr,int start,int end)//returns pivot
{
    int idx=start-1,j=start,pivot=arr[end];
    while(j<end)//when j reaches end
    {
        if(arr[j]<=pivot)//if current element is less than or equal to pivot
        {
            swap(arr[++idx],arr[j]);//place current element at idx+1
        }
        j++;
    }
    swap(arr[idx+1],arr[end]);//place pivot at idx+1
    return idx+1;
}
void Quicksort(vector<int>&arr,int start,int end)
{
    if(start<end)//if partition all is not done
    {
        int pivot=partition(arr,start,end);//pivot is returned
        Quicksort(arr,start,pivot-1);//left half
        Quicksort(arr,pivot+1,end);//right half 
    }
}
int main()
{
    vector<int>arr={10,22,11,42,15,26,18};
    Quicksort(arr,0,arr.size()-1);
    for(auto i:arr)
    {
        cout<<i<<" ";
    }
    cout<<endl;
    return 0;
}