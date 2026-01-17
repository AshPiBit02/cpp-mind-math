//Sudoku
#include<iostream>
#include<vector>
using namespace std;
bool isSafe(vector<vector<char>>&board,int row,int col,char dig)
{
    //check if dig already exists in row(Horizontal)
    for(int i=0;i<9;i++)
    {
        if(board[row][i]==dig)
        {
            return false;
        }
    }
    //check if dig alreday exists in column(vertical)
    for(int j=0;j<9;j++)
    {
        if(board[j][col]==dig)
        {
            return false;
        }
    }
    //check if dig already exists in its current 3x3 grid
    int start_row=(row/3)*3,start_col=(col/3)*3;//since each grid start with idx that is multiple of 3(first gird 0,0 second grid 0,3 third grid 0,6)
    for(int i=start_row;i<start_row+3;i++)//traverse vertically
    {
        for(int j=start_col;j<start_col+3;j++)//traverse horizontally
        {
            if(board[i][j]==dig)
            {
                return false;
            }
        }
    }
    return true;//is safe
}
bool digit_placer(vector<vector<char>>&board,int row,int col)//place digit in correct order
{
    if(row==9)//base case get called if all the digit are placed
    {
        return true;
    }
    int next_row=row,next_col=col+1;//for placing next dig at next position(i.e. same rows next column)
    if(next_col==9)//if next_col exceed the original col then next row starts and col start with zero 
    {
        next_row=row+1;
        next_col=0;
    }
    if(board[row][col]!='.')//if any digit alreday exists at current place then we move to next position by recursion
    {
        return digit_placer(board,next_row,next_col);//move to next position
    }
    //if current position is empty(i.e. '.' )then we check if place is safe for current dig or not if yes then place if no then we backtark
    for(char dig='1';dig<='9';dig++)
    {
        if(isSafe(board,row,col,dig))
        {
            board[row][col]=dig;//new dig placed at current place
            if(digit_placer(board,next_row,next_col))//to place next digit at next place
            {
                return true;
            }
            board[row][col]='.';//backtrack if next digit can be placed at next place(we remove the previous digit at previous position)
        }
    }
    return false;
}
bool sudoku_solver(vector<vector<char>>&board)
{
   return digit_placer(board,0,0);//calls digit_placer
}
int main()
{
    vector<vector<char>> sudoku = {
    {'5','3','.','.','7','.','.','.','.'},
    {'6','.','.','1','9','5','.','.','.'},
    {'.','9','8','.','.','.','.','6','.'},
    {'8','.','.','.','6','.','.','.','3'},
    {'4','.','.','8','.','3','.','.','1'},
    {'7','.','.','.','2','.','.','.','6'},
    {'.','6','.','.','.','.','2','8','.'},
    {'.','.','.','4','1','9','.','.','5'},
    {'.','.','.','.','8','.','.','7','9'}
};
    if(sudoku_solver(sudoku)){
        for (int i=0;i<9;i++)
        {
            for(int j=0;j<9;j++)
            {
                cout << sudoku[i][j] << " ";
            }
            cout << endl;
        }
    }
    else
    {
        cout<<"No solution exists";
    }
    return 0;
}