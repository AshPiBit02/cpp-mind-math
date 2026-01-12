//Will be given two sorted array we have to merge then 
#include<iostream>
#include<vector>
using namespace std;
void mergearr1(vector<int>&arr1,vector<int>&arr2)
{
    int n=arr1.size()-1,m=arr2.size()-1;
    vector<int>arr3(m+n+2);
    for(auto rit=arr3.rbegin(); rit!=arr3.rend(); ++rit)
    {
        if(n>=0 && ( m<0 || arr1[n]>arr2[m]))
        {
            *rit=arr1[n--];
        }
        else
        {
            *rit=arr2[m--];
        }
    }
    cout<<"Merged sorted array: ";
    for(int i: arr3)
    {
        cout<<i<<" ";
    }
    cout<<endl;
}
void mergearr2(vector<int>&arr1,vector<int>&arr2)
{
    int n=arr1.size()-1,m=arr2.size()-1;
    int idx1=0,idx2=0;
    vector<int>arr3(m+n+2);
    for( int i=0;i<arr3.size();i++)
    {
        if(idx1>n)
        {
            arr3[i]=arr2[idx2++];
        }
        else if(idx2>m)
        {
            arr3[i]=arr1[idx1++];
        }
        else{
            if(arr1[idx1]<arr2[idx2])
            {
                arr3[i]=arr1[idx1++];
            }else
            {
                arr3[i]=arr2[idx2++];
            }
        }
    }
    cout<<"Merged sorted array: ";
    for(int i:arr3)
    {
        cout<<i<<" ";
    }
    cout<<endl;
    
}
int main()
{
    vector<int>arr1={1,2,3};
    vector<int>arr2={2,5,6};
    mergearr1(arr1,arr2);
    mergearr2(arr1,arr2);
    return 0;
}