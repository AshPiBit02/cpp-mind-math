//Rearrange array so that positive and negative numbers alternate.
#include<iostream>
#include<algorithm>
using namespace std;
int main()
{
    int arr[]={-3,-4,6,7,8,-2,1,-9};
    int n=sizeof(arr)/sizeof(arr[0]);
    int neg=1,pos=0;
    while(neg<n)
    {
        if(arr[pos]<0 && arr[neg]>0)
        {
            swap(arr[pos],arr[neg]);
        }
        if(arr[pos]>0)
        {
            pos+=2;
        }else
        {
            neg+=2;
        }
    }
    cout<<"Array after rearrange: ";
    for(int i=0;i<n;i++)
    {
        cout<<arr[i]<<" ";
    }
}