//returns the count of subarray whose sum equals to k
#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;
int count_subarr_sum(vector<int>&arr,int k)
{
    int n=arr.size();
    int count=0;
    vector<int>prefixSum(n,0);
    prefixSum[0]=arr[0];
    for(int i=1;i<n;i++)
    {
        prefixSum[i]=arr[i]+prefixSum[i-1];
    }
    unordered_map<int,int>m;//stores prefixsum as key and frequency of that sum as value
    for(int j=0;j<n;j++)
    {
        if(prefixSum[j]==k)
        {
            count++;
        }
        int val=prefixSum[j]-k;//k=prefixSum[j]-prefixSum[i](val)
        if(m.find(val)!=m.end())//if prefixSum already exists in the map
        {
            count+=m[val];//adds the freq of j index prefix sum to the count
        }
        // if(m.find(prefixSum[j])==m.end())//if not then
        // {
        //     m[prefixSum[j]]=0;//prefixSum inserted as key with freq zero
        // }
        m[prefixSum[j]]++;//current prefixSum's freq get incremented(if already exits then freq becomes prev freq +1 if new then freq becomes 1)
    }
    return count;
}
int main()
{
    vector<int>arr={9,4,0,0,20,3,10,15};
    int target=33;
    cout<<"Subarray count equal to "<<target<<" is "<<count_subarr_sum(arr,target)<<endl;
    return 0;
}