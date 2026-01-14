/*Program to search an element in 2d matrix using binary search
Note: Each row is sorted in non-decreasing order and the first integer of each row is greater than the last integer of the previous row*/
#include<iostream>
using namespace std;
int BinSrchCol(int** matrix,int start,int end,int target,int row)
{
    if(start > end) return 0;
    int mid=start+((end-start)/2);
    if(matrix[row][mid]==target)
    {
        return 1;
    }
    else if(matrix[row][mid]<target)
    {
        return BinSrchCol(matrix,mid+1,end,target,row);
    }
    else
    {
        return BinSrchCol(matrix,start,mid-1,target,row);
    }
}
int BinSrchRow(int** matrix,int start,int end,int target,int m)
{
    if(start > end) return 0;
    int mid=start+((end-start)/2);
    if(matrix[mid][0]<=target && matrix[mid][m]>=target)
    {
        return BinSrchCol(matrix,0,m,target,mid);
    }
    else if(matrix[mid][0]>target)
    {
        return BinSrchRow(matrix,start,mid-1,target,m);
    }
    else if(matrix[mid][m]<target)
    {
        return BinSrchRow(matrix,mid+1,end,target,m);
    }
    return 0;
}
int main()
{
    int target;
    cout<<"Enter target element: ";
    cin>>target;
    int arr[3][4]={{1,3,5,7},{10,11,16,20},{23,30,34,60}};
    int* matrix[3];
    for(int i=0;i<3;i++) {
        matrix[i] = arr[i];
    }
    cout<<((BinSrchRow((int**)matrix,0,2,target,3)==1)?"Element found":"Element not found!")<<endl;
    return 0;
}
