//finds subsets of given array(even for duplicate element) using recursion and backtracking
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

void getAllsubsets(vector<int>&arr,vector<int>&ans,int i,vector<vector<int>>&allsubsets)
{
    if(i==arr.size())
    {
        allsubsets.push_back(ans);//stores subset to the allsubsets vector
        return;
    }
    //include
    ans.push_back(arr[i]);//stores elements to the subset vector ans
    getAllsubsets(arr,ans,i+1,allsubsets);
    ans.pop_back();
    int idx=i+1;
    while(idx<arr.size() && arr[idx]==arr[idx-1]) idx++;//remove skips duplicate elements
    //exclude
    getAllsubsets(arr,ans,idx,allsubsets);
}
vector<vector<int>> subsetWithDup(vector<int>&arr)
{
    sort(arr.begin(),arr.end());//need to skip repeating elements so sorting
    vector<vector<int>>allsubsets;//store all subsets
    vector<int>ans;//stores single subset's elements
    getAllsubsets(arr,ans,0,allsubsets);
    return allsubsets;
}

int main()
{
    vector<int>arr={1,2,3,3,3};
    vector<vector<int>>result=subsetWithDup(arr);
    cout<<"The subsets are: "<<endl;
    for(int i=0;i<result.size();i++)
    {
        for(int j=0;j<result[i].size();j++)
        {
            cout<<result[i][j]<<" ";
        }
        cout<<endl;
    }
    return 0;
    
}