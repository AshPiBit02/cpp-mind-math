//N queens problem
#include<iostream>
#include<vector>
#include<string>
using namespace std;
bool isSafe(vector<string>&board,int row,int col,int n)
{
    //no need to check new queen new row
    //if any other queen in the column
    for(int j=0;j<row;j++)//check before row because no chance of other queen of being at current or next row
    {
        if(board[j][col]=='Q')
        {
            return false;
        }
    }
    //check for upper diagonals since all the queens are placed serially in row to there won't be any queen below so we don't need to check lower daigonals
    //if any queen in the left upper diagonal
    for(int i=row,j=col;i>=0 && j>=0 ;i--,j--)
    {
        if(board[i][j]=='Q')
        {
            return false;
        }
    }
    //if any queen in the right upper diagonal
    for(int i=row,j=col;i>=0 && j<n ;i--,j++)
    {
        if(board[i][j]=='Q')
        {
            return false;
        }
    }
    return true;// confirms current queen at that is safe
}
//find safe position for each queens
void nQueens(vector<string>&board,int row,int n,vector<vector<string>>&ans)
{
    if(row==n)
    {
        ans.push_back(board);
        return ;
    }
    for(int i=0;i<n;i++)
    {
        if(isSafe(board,row,i,n))
        {
            board[row][i]='Q';
            nQueens(board,row+1,n,ans);
            board[row][i]='.';//Backtrack(set . as previous state )
        }
    }
}
vector<vector<string>> placenQueens(vector<string>&board,int n)
{
    vector<vector<string>>ans;
    nQueens(board,0,n,ans);
    return ans;
}
int main()
{
    int n=4;
    vector<string>board(n,string(n,'.'));//initailze n vectors with n dots each
    vector<vector<string>>res=placenQueens(board,n);
    cout<<"Safe arrangements: "<<endl;
    for(int i=0;i<res.size();i++)
    {
        cout<<"Arrangement "<<i+1<<endl;
        for(int j=0;j<res[i].size();j++)
        {
            cout<<res[i][j]<<endl;
        }
        cout<<endl;
    }
    return 0;


}