//This program takes array having equal number of positive and negative elements 
//and store inside the same array in alternative position i.e. +ve,-ve,+ve,-ve,......
#include<iostream>
using namespace std;
int main()
{
    int arr[]={-4,3,-1,-5,2,6,7,-8};
    int n=sizeof(arr)/sizeof(arr[0]);
    int temparr[n];
    int i=0,pos=0,neg=1;
    while(i<n)
    {
        if(arr[i]>0)
        {
            temparr[pos]=arr[i];
            pos+=2;
        }else
        {
            temparr[neg]=arr[i];
            neg+=2;
        }
        i++;
    }
    for(int j=0;j<n;j++)
    {
        arr[j]=temparr[j];
    }
    for(int j=0;j<n;j++)
    {
        cout<<arr[j]<<" ";
    }
    return 0;

}