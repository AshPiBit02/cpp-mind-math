//Smallest subarray with sum greater than k
//
#include<iostream>
#include<vector>
using namespace std;
void smallest_subarr(vector<int>&arr,int k)
{
    int n=arr.size();
    int subarrsum=0;
    int start=0,min_len=INT_MAX;
    int final_start=-1,final_end=-1;
    for(int end=0;end<arr.size();end++)
    {
        subarrsum+=arr[end];
        while(subarrsum>k)
        {
            if(end-start+1 < min_len)
            {
                min_len=end - start +1;
                final_start=start;
                final_end=end;
            }
            subarrsum-=arr[start];
            start++;
        }
    }
    if(final_start== -1) cout<<"No subarray exists!"<<endl;
    else
    {
        cout<<"Smallest subarray with sum greater than "<<k<<" is : ";
        for(int i=final_start;i<=final_end;i++)
        {
            cout<<arr[i]<<" ";
        }
        cout<<"\nLength: "<<min_len<<endl;
    }
}
int main()
{
    vector<int>arr={9,1,7,3,2,5,10};
    int k=10;
    smallest_subarr(arr,k);
    return 0;
}