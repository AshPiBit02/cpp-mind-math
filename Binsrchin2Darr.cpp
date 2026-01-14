//Binary search in 2D matrix II all rows and cols are in sorted order;
#include<iostream>
#include<vector>
using namespace std;
bool BinSrchII(vector<vector<int>>&mat,int target)//not exact binary search but
{
    int col=mat[0].size();
    int row=mat.size();
    int top=0;//represent first column
    int right=col-1;//represents last column
    if(target>mat[row-1][col-1] || target<mat[top][0]){return false;}
    while(top<row && right>=0)
    {

        if(mat[top][right] == target)
        {
            return true;
        }
        else if(mat[top][0]<=target && target<mat[top][right])
        {
            right--;//discard last column
        }else//remove row
        {
            top++;//discar current row
        }
    }
    return false;

}
int main()
{
    vector<vector<int>>mat={{10,12,14,16,18},{20,22,24,26,28},{30,32,34,36,38},{40,42,44,46,48},{50,52,54,56,58}};
    int target=11;
    for(int i=0;i<mat.size();i++)
    {
        for(int j=0;j<mat[i].size();j++)
        {
            cout<<mat[i][j]<<" ";
        }
        cout<<endl;
    }
    cout<<BinSrchII(mat,target);
    return 0;
}