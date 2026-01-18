//Word Search Puzzle
#include<iostream>
#include<vector>
using namespace std;
bool backtrack(vector<vector<char>>&board,const string& word,int i,int j,int index)
{
    if(index==word.size())//word found
    {
        return true;
    }
    if(i<0 || j<0 || i>=board.size() || j>=board[0].size() || board[i][j]!=word[index])//if out of bound or char doesn't match
    {
        return false;
    }
    char temp=board[i][j];//stores original char before making
    board[i][j]='#';//marks as visited
    bool found=backtrack(board,word,i-1,j,index+1)||//finds upward
                backtrack(board,word,i+1,j,index+1)||//finds downward
                backtrack(board,word,i,j-1,index+1)||//finds to the left
                backtrack(board,word,i,j+1,index+1);//finds to the right
    board[i][j]=temp;//restoring original char (backtracking)
    return found;
}
bool exists(vector<vector<char>>&board,const string& word)
{
    int row=board.size(),col=board[0].size();
    for(int i=0;i<row;i++)
    {
        for(int j=0;j<col;j++)
        {
            if(board[i][j]==word[0] && backtrack(board,word,i,j,0))
            {
                return true;
            }
        }
    }
    return false;
}
int main()
{
    vector<vector<char>>board={{'A','B','C','E'},{'S','F','C','S'},{'A','D','E','F'}};
    string word1="ABCCED";
    string word2="ABCCEF";
    cout<<"\nResult for word1: "<<(exists(board,word1)?"True":"False");
    cout<<"\nResult for word2: "<<(exists(board,word2)?"True":"False");
    return 0;
}