//Move all zeroes to the end while keeping order of others.
#include<iostream>
#include<algorithm>
using namespace std;
int main()
{
    int arr[]={0,1,5,0,3,0,9,0};
    int n=sizeof(arr)/sizeof(arr[0]);
    int i=0,j=0;
    while(j<n)
    {
        if(arr[j]!=0)
        {
            swap(arr[i],arr[j]);
            i++;
        }
        j++;
    }
    cout<<"Result: ";
    for(int k=0;k<n;k++)
    {
        cout<<arr[k]<<" ";
    }
    return 0;
}