//This program is to solve peak index probem wher there are multiple peak inside a single array
#include<iostream>
using namespace std;
void allPeakIndex(int* arr,int n)
{
    for(int i=1;i<n-1;i++)//i=1 to n-1 because first and last element can be peak index
    {
        if(arr[i]>arr[i-1] && arr[i]>arr[i+1])
        {
            cout<<i<<" ";
        }
    }
}
int main()
{
    int arr[]={2,5,3,6,9,4,7,2,5,1};
    int n=sizeof(arr)/sizeof(arr[0]);
    cout<<"The peak indexes are :"<<endl;
    allPeakIndex(arr,n);
    return 0;

}