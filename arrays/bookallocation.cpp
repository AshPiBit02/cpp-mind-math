
#include<iostream>
#include<vector>
using namespace std;
bool isValid(vector<int>&arr,int n,int m,int maxallowed)
{
    int student=1,pages=0;
    for(int i=0;i<n;i++)
    {
        if(arr[i]>maxallowed)
        {
            return false;
        }
        if(arr[i]+pages<=maxallowed)
        {
            pages+=arr[i];
        }
        else
        {
            student++;
            pages=arr[i];
        }
    }
    return student>m?false:true;
}
int allocatebook(vector<int>&arr,int n,int m)
{
    int sum=0;
    for(int i=0;i<n;i++)
    {
        sum+=arr[i];
    }
    int start=0,end=sum,ans=-1;
    while(start<=end)
    {
        int mid=start+(end-start)/2;
        if(isValid(arr,n,m,mid))
        {
            ans=mid;
            end=mid-1;
        }
        else
        {
            start=mid+1;
        }
    }
    return ans;
}
int main()
{
    vector<int>arr={2,1,3,4};
    int n=arr.size();
    int m=2;//number of students
    cout<<allocatebook(arr,n,m);
    return 0;
    

}