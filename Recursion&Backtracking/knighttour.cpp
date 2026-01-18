//Knight Tour
#include<iostream>
#include<vector>
using namespace std;
bool isvalid(vector<vector<int>>&gird,int row,int col,int n,int expectedVal)
{
    if(row<0 || col<0 || row>=n || col>=n || (gird[row][col]!=expectedVal))
    {
        return false;
    }
    if(gird[row][col]==(n*n)-1)//
    {
        return true;
    }
    // Try all 8 possible knight moves
    int ans1=isvalid(gird,row-2,col-1,n,expectedVal+1);
    int ans2=isvalid(gird,row-2,col+1,n,expectedVal+1);
    int ans3=isvalid(gird,row-1,col+2,n,expectedVal+1);
    int ans4=isvalid(gird,row+1,col+2,n,expectedVal+1);
    int ans5=isvalid(gird,row+2,col+1,n,expectedVal+1);
    int ans6=isvalid(gird,row+2,col-1,n,expectedVal+1);
    int ans7=isvalid(gird,row+1,col-2,n,expectedVal+1);
    int ans8=isvalid(gird,row-1,col-2,n,expectedVal+1);
    return ans1||ans2||ans3||ans4||ans5||ans6||ans7||ans8;
}
bool isKnightTourValid(vector<vector<int>>&grid)
{
    return isvalid(grid,0,0,grid.size(),1);
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

