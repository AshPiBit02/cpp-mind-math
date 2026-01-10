//Count contiguous subarrays with sum eqaul to k.
#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;
int count_subarr(vector<int>&arr,int target)
{
    int n=arr.size();
    int count=0;
    vector<int>prefixsum(n,0);//initialize with size n and value zero
    prefixsum[0]=arr[0];
    for(int i=1;i<n;i++)
    {
        prefixsum[i]=prefixsum[i-1]+arr[i];
    }
    unordered_map<int,int>m; //stores prefixsum with its frequency
    for(int j=0;j<n;j++)
    {
        if(prefixsum[j]==target)
        {
            count++;
        }
        int val=prefixsum[j]-target;
        if(m.find(val)!=m.end())
        {
            count+=m[val];
        }
        if(m.find(prefixsum[j])==m.end())
        {
            m[prefixsum[j]]=0;
        }
        m[prefixsum[j]]++;
    }
    return count;
}
int main()
{
   vector<int>arr={1,-1,2,3,-2,4};
   int k=3; 
   cout<<count_subarr(arr,k);
   return 0;

}