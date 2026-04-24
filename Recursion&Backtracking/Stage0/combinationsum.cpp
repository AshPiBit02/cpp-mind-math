//Finds combination of an array such that the sum of their elements gets equal to target
#include<iostream>
#include<vector>
using namespace std;
void getcombi(vector<int>&arr,int idx,int tar,vector<vector<int>>&ans,vector<int>&combi)
{
    if(tar==0)//means subarray with sum equal to target found
    {
        ans.push_back(combi);
        return;
    }
    if(tar<0 || idx==arr.size())//means subarray with sum greater than target and exceeds the size of array
    {
        return ;
    }
    combi.push_back(arr[idx]);//add element at idx to the combi vector
    getcombi(arr,idx,tar-arr[idx],ans,combi);//includes element at idx for multiple times
    combi.pop_back();//removes the last element from the combi array for exclusion (backtracking)
    getcombi(arr,idx+1,tar,ans,combi);//excludes element at idx 
}
vector<vector<int>> combiWithSum(vector<int>&arr,int target)
{
    vector<vector<int>>ans;
    vector<int>combi;
    getcombi(arr,0,target,ans,combi);
    return ans;
}
int main()
{
    vector<int>arr={1,3,5};
    int target=8;
    auto res=combiWithSum(arr,target);
    cout<<"The combination with sum "<<target<<" are :"<<endl;
    for(auto i:res)
    {
        for(auto j: i)
        {
            cout<<j<<" ";
        }
        cout<<endl;
    }
    return 0;
}