//sort an array of 0s, 1s and 2s.
#include<iostream>
using namespace std;
int main()
{
    int arr[]={0,2,0,0,1,1,2,0,2,1,2,1,2,1};
    int n=sizeof(arr)/sizeof(arr[0]);
    int count_0=0,count_1=0,count_2=0;
    for(int i=0;i<n;i++)
    {
        if(arr[i]==0)
        {
            count_0++;
        }else if(arr[i]==1)
        {
            count_1++;
        }else{
            count_2++;
        }
    }
    cout<<"Sorted array: ";
    for(int i=0;i<n;i++)
    {
        if(count_0>0)
        {
            cout<<" 0 ";
            count_0--;
        }
        if(count_0==0 && count_1>0)
        {
            cout<<" 1 ";
            count_1--; 
        }
        if(count_0==0 && count_1==0 && count_2>0)
        {
            cout<<" 2 ";
            count_2--;
        }
    }
}