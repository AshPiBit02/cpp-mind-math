//This program remove the desired element of an array using two pointer approach
#include<iostream>
using namespace std;
int main()
{
    int value=7;
    int arr[]={3,4,7,5,7,6,2,3,0};
    int n=sizeof(arr)/sizeof(arr[0]),i=0,j=0;
    while(j<n)
    {
        if(arr[j]!=value)
        {
            arr[i]=arr[j];
            i++;
        }
        j++;
    }
    for(int k=0;k<i;k++)
    {
        cout<<arr[k]<<" ";
    }
    return 0;

}