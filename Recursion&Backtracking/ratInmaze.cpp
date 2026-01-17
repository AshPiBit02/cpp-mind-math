//Rat in Maze using recursion and backtracking
#include<iostream>
#include<vector>
using namespace std;
void helper(vector<vector<int>>&mat,int r,int c,string path,vector<string>&ans,vector<vector<bool>>&visited)
{
    int n=mat.size();
    if(r<0 || c<0 || r>=n || c>=n || mat[r][c]==0 || visited[r][c]==true)//if no path or already visited then
    {
        return;
    }
    if(r==n-1 && c==n-1)//base case (path found)
    {
        ans.push_back(path);
        return;
    }
    visited[r][c]=true;//mark the current position as true(i.e. visited)
    helper(mat,r-1,c,path+" U ",ans,visited);//goes down for path if possible then goes else return
    helper(mat,r+1,c,path+" D ",ans,visited);//goes upward for path if possible then goes else return
    helper(mat,r,c+1,path+" R ",ans,visited);//goes right for path if possible then goes else return
    helper(mat,r,c-1,path+" L ",ans,visited);//goes left for path if possible then goes else return
    visited[r][c]=false;//mark unvisited for other path(backtracking)
}
vector<string> findpath(vector<vector<int>>&mat)
{
    int n=mat.size();
    vector<string>ans;
    string path="";
    vector<vector<bool>>visited(n,vector<bool>(n,false));//keep track of previous position to ensure no loop formation
    helper(mat,0,0,path,ans,visited);
    return ans;
}
int main()
{
    vector<vector<int>>mat={{1,0,0,0},{1,1,0,1},{1,1,0,0},{0,1,1,1}};//1 means path is possible and 0 means not possible
    auto res=findpath(mat);//auto automatically deduce the type of a variable from the value used to initialize it.
    cout<<"The possible paths are: "<<endl;
    for(auto i:res)//auto automatically deduce the type of a variable from the value used to initialize it.
    cout<<i<<endl;
    return 0;
}
