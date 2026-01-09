//Count how many elements are greater than the average of the array.
#include<iostream>
int n,i;
#define loop for(i=0;i<n;i++)
using namespace std;
int ele_greater_than_avg(int* arr,int n)
{
    int arr_sum=0,count=0;
    loop
    {
        arr_sum+=arr[i];
    }
    loop
    {
        if((n*arr[i])>arr_sum)
        {
            count++;
        }
    }
    return count;
}
int main()
{
    int arr[]={4,5,13,3,7,12,22,1,9,34};
    n=sizeof(arr)/sizeof(arr[0]);
    cout<<"Number of elements greater than average: "<<ele_greater_than_avg(arr,n);
    return 0;


}