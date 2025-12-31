//This program moves zeros at last of the array;
#include<iostream>
#include<algorithm>
using namespace std;
int main()
{
    int arr[]={2,0,3,0,0,5,4,8,0,7};
    int n=sizeof(arr)/sizeof(arr[0]);
    int i=0,j=1;
    while(j<n)
    {
        if(arr[i]==0 && arr[j]!=0)
        {
            swap(arr[i],arr[j]);
            i++;
            j++;
        }
        else if(arr[j]==0 && arr[i]==0)
        {
            j++;
        }
        else
        {
            i++;
            j++;
        }
    }
    for(int k=0;k<n;k++)
    {
        cout<<arr[k]<<" ";
    }
    return 0;
}