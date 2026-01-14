//Find the next permutation of the given array;
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
void nextpermutation(vector<int>&arr)
{
    int n=arr.size();
    int pivot=-1;
    for(int i=n-2;i>=0;i--)//runs from second last element
    {
        if(arr[i]<arr[i+1])
        {
            pivot=i;
            break;
        }
    }
    if(pivot==-1)//if pivot is not found
    {
        reverse(arr.begin(),arr.end());
        return;
    }
    for(int i=n-1;i>pivot;i--)//find the smallest element greater than pivot
    {
        if(arr[i]>arr[pivot])
        {
            swap(arr[i],arr[pivot]);
            break;
        }
    }
    reverse(arr.begin()+pivot+1,arr.end());

}
int main()
{
    vector<int>arr={1,2,3,6,5,4};
    nextpermutation(arr);
    cout<<"The next permutation is : ";
    for(int i:arr)
    {
        cout<<i<<" ";
    }
    cout<<endl;
    return 0;
}