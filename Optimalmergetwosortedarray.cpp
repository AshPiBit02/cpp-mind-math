//Merge two sorted array without using any extra space(there will be sorted array and no of zeros equal to the size second array )
//we have to store the elements of the second array to the first inorder that the first array have element of second array and its own in the sorted order
#include<iostream>
#include<vector>
using namespace std;
void mergetarr(vector<int>&arr1,vector<int>&arr2,int m,int n)
{
    for(int i=arr1.size()-1;i>=0;i--)
    {
        if(n<0 || (arr1[m]>arr2[n]))
        {
            arr1[i]=arr1[m--];
        }
        else
        {
            arr1[i]=arr2[n--];
        }
    }
}
int main()
{
    vector<int>arr1={1,2,3,0,0,0};
    vector<int>arr2={2,5,6};
    mergetarr(arr1,arr2,2,arr2.size()-1);
    cout<<"The merged sorted array is : ";
    for(int i:arr1)
    {
        cout<<i<<" ";
    }
    return 0;
}