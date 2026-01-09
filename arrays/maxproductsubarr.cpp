//find the maximum product subarray.
#include<iostream>
#include<algorithm>
using namespace std;    
int main()
{
    int arr[]={1,-2,-3,0,7,-8,-2};
    int n=sizeof(arr)/sizeof(arr[0]);
    int max_product=arr[0];
    int min_product=arr[0];
    int result=arr[0];
    int start=0,end=0,temp_start=0;
    for(int i=0;i<n;i++)
    {
        //swap when negative
        if(arr[i]<0)
        {
            swap(max_product,min_product);
        }
        //update max product
        if(arr[i]>max_product*arr[i])
        {
            max_product=arr[i];
            temp_start=i;
        }
        else
        {
            max_product*=arr[i];
        }
        //update min product
        min_product=min(arr[i],min_product*arr[i]);
        // update result
        if(max_product>result)
        {
            result=max_product;
            start=temp_start;
            end=i;
        }
    }
    cout<<"The maximum product subarray: ";
    for(int i=start;i<=end;i++)
    {
        cout<<arr[i]<<" ";
    }
    cout<<"\nThe product is "<<max_product<<endl;
    return 0;
}