//Rat in Maze using recursion and backtracking
#include<iostream>
#include<vector>
using namespace std;
void helper(vector<vector<int>>&mat,int r,int c,string path,vector<string>&ans)
{
    int n=mat.size();
    if(r<0 || c<0 || r>=n || c>=n || mat[r][c]==0 || mat[r][c]==-1)//if no path or already visited
    {
        return;
    }
    if(r==n-1 && c==n-1)//base case (path found)
    {
        ans.push_back(path);
        return;
    }
    mat[r][c]=-1;//mark the current position as true(i.e. visited)
    helper(mat,r-1,c,path+" U ",ans);//goes down for path if possible then goes else return
    helper(mat,r+1,c,path+" D ",ans);//goes upward for path if possible then goes else return
    helper(mat,r,c+1,path+" R ",ans);//goes right for path if possible then goes else return
    helper(mat,r,c-1,path+" L ",ans);//goes left for path if possible then goes else return
    mat[r][c]=1;//mark unvisited for other path(backtracking)
}
vector<string> findpath(vector<vector<int>>&mat)
{
    int n=mat.size();
    vector<string>ans;
    string path="";
    helper(mat,0,0,path,ans);
    return ans;
}
int main()
{
    vector<vector<int>>mat={{1,1,0,0},{1,1,0,1},{1,1,0,0},{0,1,1,1}};//1 means path is possible and 0 means not possible
    auto res=findpath(mat);//auto automatically deduce the type of a variable from the value used to initialize it.
    cout<<"The possible paths are: "<<endl;
    for(auto i:res)//auto automatically deduce the type of a variable from the value used to initialize it.
    cout<<i<<endl;
    return 0;
}
