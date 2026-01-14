//Returns the sum of diagonal sum of 2D matrix
#include<iostream>
#include<vector>
using namespace std;
int dia_sum(const vector<vector<int>>&mat,int rows,int cols)
{
    int primarydiagonal_sum=0;//left to right diagonal 
    int secondarydiagonal_sum=0;//right to left diagonal
    for(int i=0;i<rows;i++)
    {
        primarydiagonal_sum+=mat[i][i];
        if(i!=rows-i-1)
        {
            secondarydiagonal_sum+=mat[i][rows-i-1];
        }
    }
    return primarydiagonal_sum+secondarydiagonal_sum;
}

int main()
{
    vector<vector<int>>mat={{1,2,3},{4,5,6},{7,8,9}};
    cout<<dia_sum(mat,3,3);
    return 0;

}
