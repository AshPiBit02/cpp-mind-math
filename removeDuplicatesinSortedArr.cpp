//This program remove the redundent element of the sorted array
#include<iostream>
using namespace std;
int main()
{
    int arr[]={1,1,2,2,3,3,3,4,4,5,7,7,9};
    int n=sizeof(arr)/sizeof(arr[0]),i=0,j=1;
    while(j<n)
    {
        if(arr[i]!=arr[j])
        {
            i++;
            arr[i]=arr[j];
        }
        j++;
    }
    cout<<"Resulting Array is: ";
    for(int x=0;x<=i;x++)
    {
        cout<<arr[x]<<" ";
    }
    return 0;

    
}