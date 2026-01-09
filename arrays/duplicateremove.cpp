//Remove duplicates from a stored array in place.
#include<iostream>
using namespace std;
int main()
{
    int arr[]={1,2,3,3,4,5,5,5,6,6,7};
    int n=sizeof(arr)/sizeof(arr[0]);
    int slow=0,fast=1;
    while(fast<n)
    {
        if(arr[slow]!=arr[fast])
        {
            arr[++slow]=arr[fast];
        }
        fast++;

    }
    cout<<"Array after removing duplicates: ";
    for(int i=0;i<=slow;i++)
    {
        cout<<arr[i]<<" ";
    }
}