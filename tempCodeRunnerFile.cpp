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