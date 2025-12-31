//This program rotates the array to the right by k steps without using additional arrray
#include<iostream>
#include<algorithm>
using namespace std;
void reverse(int arr[],int i,int n)
{
    while(i<n)
    {
        swap(arr[i],arr[n]);
        i++;
        n--;
    }
}
void rotate(int arr[],int k,int n)
{
    reverse(arr,0,n);
    reverse(arr,0,k-1);
    reverse(arr,k,n);
}
void displayArr(int arr[],int n)
{
    cout<<"The Array after rotating to the right 3 steps is:  ";
    for(int i=0;i<=n;i++)
    {
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}
int main()
{
    int arr[]={1,2,3,4,5,6,7};
    int n=sizeof(arr)/sizeof(arr[0])-1;
    int k=3;
    rotate(arr,k,n);
    displayArr(arr,n);
    return 0;
}