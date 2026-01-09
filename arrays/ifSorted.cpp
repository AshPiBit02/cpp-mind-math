//Checks if the array is already sorted in ascending order.
#include<iostream>
using namespace std;
int main()
{
    int arr[]={1,3,4,7,8,15,14};
    int n=sizeof(arr)/sizeof(arr[0]);
    for(int i=1;i<n;i++)
    {
        if(arr[i]<arr[i-1])
        {
            cout<<"Not in ascending order!"<<endl;
            return 0;
        }
    }
    cout<<"In ascending order"<<endl;
    return 0;
}