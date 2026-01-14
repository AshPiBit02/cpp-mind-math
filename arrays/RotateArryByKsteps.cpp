//This program rotates the array to the right by k steps using additional arrray
#include<iostream>
using namespace std;
int main()
{
    int arr[]={1,2,3,4,5,6,7};
    int n=sizeof(arr)/sizeof(arr[0]);
    int k=3,temparr[n];
    for(int i=0;i<n;i++)
    {
        temparr[k]=arr[i];
        k=(k+1)%n;
    }
    for(int i=0;i<n;i++)
    {
        cout<<temparr[i]<<" ";
    }
    return 0;


}