//Inversion count
#include<iostream>
#include<vector>
using namespace std;
// Merge two sorted halves of the array and count inversions
int merge(vector<int>&arr,int start,int mid,int end)
{
    int i=start,j=mid+1;
    int invcount=0;
    vector<int>temp;
    // Merge two sorted halves of the array and count inversions
    while(i<=mid && j<=end)
    {
        if(arr[i]<=arr[j])
        {
            temp.push_back(arr[i++]);// no inversion, just take left element
        }else
        {
            temp.push_back(arr[j++]); // right element is smaller → inversion
            invcount+=(mid-i+1);// all remaining elements in left half form inversions
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
// Recursive mergesort function that returns total inversion count
int mergesort(vector<int>&arr,int start,int end)
{
    if(start<end)
    {
        int mid=start+(end-start)/2;
        // Count inversions in left half
        int inversionleft=mergesort(arr,start,mid);
        // Count inversions in right half
        int inversionright=mergesort(arr,mid+1,end);
          // Count split inversions during merge
        int invcount=merge(arr,start,mid,end);
        return inversionleft+inversionright+invcount;
    }
    return 0;
}
int main()
{
    vector<int>arr={6,3,5,2,7};
    cout<<"Inversion count: "<<mergesort(arr,0,arr.size()-1)<<endl;
    // for(auto i:arr)
    // {
    //     cout<<i<<" ";
    // }
    // cout<<endl;
    return 0;
}