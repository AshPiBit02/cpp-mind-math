//Finds the single element in sorted array
#include<iostream>
using namespace std;
int BinSingEle(int* arr,int start,int end)
{
    while(start<=end)
    {
        int mid=start+(end-start)/2;
        if(mid==start && arr[start]!=arr[start+1]) return start;//left corner case
        if(mid==end && arr[end]!=arr[end-1]) return end;//right corner case;
        if(arr[mid]!=arr[mid-1] && arr[mid]!=arr[mid+1])// if the mid element doesn't equal to its adjecent element then it is unique 
        {
            return mid;
        }
        else{
            if(mid%2==0)/*if the no. of elements on the either side are even ,then we need to check if the right or left element 
            is equal to the mid. If the left of mid element is equal to mid then in the left side there are odd no. of element\s remaing on the left side
             which means that there must be one single elelement, else the one single element is on right right(mid and mid+1 element are equal).*/
            {
                if(arr[mid]==arr[mid-1])
                {
                    end=mid-1;
                }else
                {
                    start=mid+1;
                }          
            }
            else/*in case of odd element on the either side of partition , we need to check if the right or left element is equal to the mid. 
            If the mid-1 and mid are equal then ther are even no of elements left on the left side which means that there is no chance of
            begin single element of left side so we check find and get the single element ont the right side. Else if the mid and mid+1 are equal then 
            the single element is on the left side i.e. before the current partition*/
            {
                if(arr[mid]==arr[mid-1])
                {
                    start=mid+1;
                }else
                {
                    end=mid-1;
                }
            }
        }
    }
    
}
int main()
{
    int arr[]={1,1,2,2,3,3,4,4,9};
    int n=sizeof(arr)/sizeof(arr[0]);
    cout<<"The element is at index: "<<BinSingEle(arr,0,n-1);
    return 0;
}