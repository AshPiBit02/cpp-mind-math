//Knight Tour
#include<iostream>
#include<vector>
using namespace std;
bool isvalid(vector<vector<int>>&grid,int row,int col,int n,int expectedVal)
{
    if(row<0 || col<0 || row>=n || col>=n || (grid[row][col]!=expectedVal))//out of bound
    {
        return false;
    }
    if(grid[row][col]==n*n-1)//last cell(base case)
    {
        return true;
    }
    //all 8 possible knight moves
    int dx[] = {-2,-2,-1,1,2,2,1,-1};
    int dy[] = {-1,1,2,2,1,-1,-2,-2};
    // Try all 8 moves
    for (int i = 0; i < 8; i++)
    {
        int newRow = row + dx[i];
        int newCol = col + dy[i];
        if (isvalid(grid, newRow, newCol, n, expectedVal + 1))
        {
            return true;
        }
    }
    return false;
}
bool isKnightTourValid(vector<vector<int>>&grid)
{
    return isvalid(grid,0,0,grid.size(),0);
} 
int main()
{
    vector<vector<int>> grid = {
        {0, 59, 38, 33, 30, 17, 8, 63},
        {37, 34, 31, 60, 9, 62, 29, 16},
        {58, 1, 36, 39, 32, 27, 18, 7},
        {35, 48, 41, 26, 61, 10, 15, 28},
        {42, 57, 2, 49, 40, 23, 6, 19},
        {47, 50, 45, 54, 25, 20, 11, 14},
        {56, 43, 52, 3, 22, 13, 24, 5},
        {51, 46, 55, 44, 53, 4, 21, 12}
    };
    if (isKnightTourValid(grid))
        cout << "Valid Knight's Tour" << endl;
    else
        cout << "Invalid Knight's Tour" << endl;

    return 0;
}

