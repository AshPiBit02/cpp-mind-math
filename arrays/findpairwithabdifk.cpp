//Find pair with absoluted difference k
#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;
vector<pair<int,int>> findPairAbDk(const vector<int>&arr,int k)
{
    unordered_map<int,vector<int>>mp;
    vector<pair<int,int>>res;
    for(int i=0;i<arr.size();i++)
    {
        int num=arr[i];
        if(mp.find(num-k)!=mp.end())
        {
            for(int idx:mp[num-k])
            {
                res.emplace_back(idx,i);
            }
        }
        if(mp.find(num+k)!=mp.end())
        {
            for(int idx: mp[num+k])
            {
                res.emplace_back(idx,i);
            }
        }
        mp[num].push_back(i);
    }
    return res;
}
int main()
{
    vector<int>arr={1,5,3,4,2};
    int k=2;
    auto pairs=findPairAbDk(arr,k);
    cout<<"The pairs are: "<<endl;
    for(auto &p: pairs)
    {
        cout<<"["<<arr[p.first]<<"("<<p.first<<"),"<<arr[p.second]<<"("<<p.second<<")]"<<endl;
    }
    return 0;
}