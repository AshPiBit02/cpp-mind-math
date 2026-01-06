#include<iostream>
#include<vector>
using namespace std;
void sprialMatrix(vector<vector<int>>&matrix)
{
    if(matrix.empty())
    {
        return;
    }
    int top=0;
    int bottom=matrix.size()-1;
    int left=0;
    int right=matrix[0].size()-1;
    while(top<=bottom && left <=right)
    {
        //Traverse from left to right
        for(int j=left;j<=right;j++)
        {
            cout<<matrix[top][j]<<"  ";
        }
        top++;
        //Traverse from top to bottom
        for(int i=top;i<=bottom;i++)
        {
            cout<<matrix[i][right]<<" ";
        }
        right--;
        //Traverse from right to left (if valid)
        if(top<=bottom)
        {
            for(int j=right;j>=left;j--)
            {
                cout<<matrix[bottom][j]<<" ";
            }
            bottom--;
        }
            //Traverse from bottom to top( if valid)
            if(left<=right)
            {
                for(int i=bottom;i>=top;i--)
                {
                    cout<<matrix[i][left]<<" ";
                }
                left++;
            }
    }
}
int main()
{
    vector<vector<int>>matrix={
    {  1,  2,  3,  4,  5,  6,  7 },
    { 20, 21, 22, 23, 24, 25,  8 },
    { 19, 32, 33, 34, 35, 26,  9 },
    { 18, 31, 30, 29, 28, 27, 10 },
    { 17, 16, 15, 14, 13, 12, 11 }
};
;
    sprialMatrix(matrix);
    return 0;

}