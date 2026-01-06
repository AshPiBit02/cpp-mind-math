//spiral matrix using vector
#include<iostream>
#include<vector>
using namespace std;
vector<int> spiralMatrix(vector<vector<int>>&mat)//vector<int> is the return type that returns multiple values of type int of vector
{
    vector<int>result;
    int left=0,top=0;
    int right=mat[0].size()-1;//number of columns -1 because we are using index
    int bottom=mat.size()-1;//number of rows -1 of same reason
    while(left<=right && top<=bottom)
    {
        //traverse from left to right
        for(int i=left;i<=right;i++)
        {
            result.push_back(mat[top][i]);
        }
        top++;
        //traverse from top to bottom
        for(int j=top;j<=bottom;j++)
        {
            result.push_back(mat[j][right]);
        }
        right--;
        //traverse from right to left
        if(top<=bottom)
        {
            for(int i=right;i>=left;i--)
            {
                result.push_back(mat[bottom][i]);
            }
            bottom--;
        }
        //traverse from bottom to top
        if(left<=right)
        {
            for(int j=bottom;j>=top;j--)
            {
                result.push_back(mat[j][left]);
            }
            left++;
        }
    }
    return result;

}
int main()
{
    vector<vector<int>>mat={{1,2,3},{4,5,6},{7,8,9},{10,11,12}};
    auto resu=spiralMatrix(mat);// auto automatically deduce the type of a variable from the value used to initialize it.

    for(int x:resu){ 
        cout<<x<<" -> ";
    }
    cout<<" NULL "<<endl;

}