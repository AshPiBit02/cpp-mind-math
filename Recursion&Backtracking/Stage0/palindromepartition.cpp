//Finds palindrome partition of given string
#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
using namespace std;
bool ispalindrome(const string& str)
{
    string rev=str;
    reverse(rev.begin(),rev.end());
    if(rev!=str)
    {
        return false;
    }
    return true;

}
void getpartition(string str,vector<string>&partition,vector<vector<string>>&ans)
{
    if(str.size()==0)//base case
    {
        ans.push_back(partition);//pushing partition to ans
        return;
    }
    for(int i=0;i<str.size();i++)//iterating over string to find partition
    {
        string part=str.substr(0,i+1);//partition of string to check if it is palindrome
        if(ispalindrome(part))//if then push to ans
        {
            partition.push_back(part);//pushing partition to partition vector
            getpartition(str.substr(i+1),partition,ans);//recursive call
            partition.pop_back();//backtracking
        }
    }
}
vector<vector<string>> partition(string& str)
{
    vector<string>partition;
    vector<vector<string>>ans;
    getpartition(str,partition,ans);
    return ans;
}
int main()
{
    string str="aas";
    vector<vector<string>>ans=partition(str);
    for(int i=0;i<ans.size();i++)
    {
        for(int j=0;j<ans[i].size();j++)
        {
            cout<<ans[i][j]<<" ";
        }
        cout<<endl;
    }
    return 0;
}