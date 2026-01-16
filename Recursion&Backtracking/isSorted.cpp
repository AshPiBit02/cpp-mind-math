//Check if given array is sorted in ascending order using recursion
#include<iostream>
#include<vector>
using namespace std;
int isSorted(vector<int>&arr,int n)
{
    if(n==1 || n==0)//n==0 handles if array is of single element
    {
        return true;
    }
    return arr[n-1]>arr[n-2] && isSorted(arr,n-1); // if last and second last elements are sorted we move to left
}
int main()
{
    vector<int>arr={1,2,0,4,5};
    cout<<isSorted(arr,arr.size());
    return 0;
}