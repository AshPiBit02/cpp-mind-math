//This program find the largest and second largest element of an array without sorting
#include<iostream>
using namespace std;
int main()
{
    int arr[]={8,31,12,63,-45,25,2,49};
    int n=sizeof(arr)/sizeof(arr[0]);
    int fLarge=0,sLarge=0;
    for(int i=0;i<n;i++)
    {
        if(arr[i]>fLarge)
        {
            sLarge=fLarge;
            fLarge=arr[i];
        }
        else if(arr[i]>sLarge)//For redundant elements we use arr[i]>sLarge && arr[i]!=fLargest inside this condition
        {
            sLarge=arr[i];
        }
    }
    cout<<"The Largest and second Largest elements are: "<<fLarge<<" & "<<sLarge<<endl;
    return 0;
}