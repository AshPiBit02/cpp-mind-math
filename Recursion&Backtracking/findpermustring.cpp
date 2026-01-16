//finds permutation of string
#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;
void getPermutation(vector<string>&str,int idx,vector<vector<string>>&ans)
{
    if(idx==str.size())
    {
        ans.push_back(str);
        return;
    }
    for(int i=idx;i<str.size();i++)
    {
        swap(str[idx],str[i]);
        getPermutation(str,idx+1,ans);
        swap(str[idx],str[i]);
    }
}
vector<vector<string>> permute(vector<string>&str)
{
    vector<vector<string>>ans;
    getPermutation(str,0,ans);
    return ans;
}
int main()
{
    vector<string>str={"a","b","c"};
    vector<vector<string>>res=permute(str);
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