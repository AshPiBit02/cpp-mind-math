//Count Pairs with absolute difference k
#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;
int count_pair_diff_k(vector<int>&arr,int k)
{
    int n=arr.size(),count=0;
    unordered_map<int,int>mp;
    for(auto &a: arr)
    {
        if(mp.find(a-k)!=mp.end())
        {
            count+=mp[a-k];//add frequency of (a-k)
        }
        if(mp.find(a+k)!=mp.end())
        {
            count+=mp[a+k];//add frequency of (a+k)
        }
        mp[a]++;//increment frequency of a
    }
        
    return count;
}
int main()
{
    vector<int>arr={1,5,3,4,2};
    cout<<count_pair_diff_k(arr,2);
    return 0;
}