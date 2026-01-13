//Program find the previous permutation of the array
#include<iostream>
#include<algorithm>
using namespace std;
void previousPermutation(vector<int>&arr)
{
    int n=arr.size(),pivot=-1;
    for(int i=n-2;i>=0;i--)
    {
        if(arr[i]>arr[i+1])
        {
            pivot=i;
            break;
        }
    }
    if(pivot==-1)
    {
        reverse(arr.begin(),arr.end());
        return;
    }
    for(int i=n-1;i>pivot;i--)
    {
        if(arr[pivot]>arr[i])
        {
            swap(arr[pivot],arr[i]);
            break;
        }
    }
    reverse(arr.begin()+pivot+1,arr.end());
}
int main()
{
    vector<int>arr={1,4,2,3,5};
    previousPermutation(arr);
    for(int i: arr)
    {
        cout<<i<<" ";
    }
    cout<<endl;



}