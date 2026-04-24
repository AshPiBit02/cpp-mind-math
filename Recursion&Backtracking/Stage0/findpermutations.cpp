//finds the permutation of given array 
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
void getpermutation(vector<int>&arr,int idx,vector<vector<int>>&ans)
{
    if(idx==arr.size())
    {
        ans.push_back(arr);
        return;
    }
    for(int i=idx;i<arr.size();i++)
    {
        swap(arr[idx],arr[i]);//placing ith index value at index idx
        getpermutation(arr,idx+1,ans);
        swap(arr[idx],arr[i]);//backtarking (goes back to previously swaped position to form new combination)
    }
}
vector<vector<int>>permute(vector<int>&arr)
{
    vector<vector<int>>ans;
    getpermutation(arr,0,ans);
    return ans;
}
int main()
{
    vector<int>arr={1,2,3};
    vector<vector<int>>res=permute(arr);
    cout<<"The permutations are: "<<endl;
    for(int i=0;i<res.size();i++)
    {
        for(int j=0;j<res[i].size();j++)
        {
            cout<<res[i][j]<<" ";
        }
        cout<<endl;
    }
    return 0;
}