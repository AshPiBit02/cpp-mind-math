//find the maximum product subarray.
#include<iostream>
using namespace std;    
int main()
{
    int arr[]={1,-2,-3,0,7,-8,-2};
    int n=sizeof(arr)/sizeof(arr[0]);
    int max_product=arr[0];
    int current_product=1;
    int start=0,current_start=0,max_len=1;
    for(int i=0;i<n;i++)
    {
        current_product*=arr[i];
        if(current_product>max_product)
        {
            max_product=current_product;
            start=current_start;
            max_len=i-current_start+1;
        }
        if(current_product==0)
        {
            current_product=1;
            current_start=i+1;
        }
    }
    cout<<"The maximum product subarray: ";
    for(int i=start;i<start+max_len;i++)
    {
        cout<<arr[i]<<" ";
    }
    cout<<"\nThe product is "<<max_product<<endl;
    return 0;
}