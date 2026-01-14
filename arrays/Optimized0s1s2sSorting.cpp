/*Sorting array of 0s, 1s & 2s using Dutch National Flag Alorithm.
we take four partition first contains only 0s, second contains 1s , third contains unsorted element i.e. the original array and the fourth part conatins 2s
0-------(l-1) l-------(m-1) m--------(h-1) h---------(n-1)*/
#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
void sortArr(vector<int>&arr)
{
    int n=arr.size();
    int mid=0,low=0,high=n-1;
    while(mid<high)
    {
        if(arr[mid]==0)
        {
            swap(arr[low],arr[mid]);//goes to the starting of second part and the mid shifts to the right
            low++;
            mid++;
        }else if(arr[mid]==2)
        {
            swap(arr[mid],arr[high]);//goes to the ending fourth part and high lefts to left
            high--;
        }else
        {
            mid++;//previous mid position contained 1 so it get merged with second part and the mid shift to the right
        }
    }
}
int main()
{
    vector<int>arr={2,0,2,1,1,0,1,2,0,0};
    cout<<"Before Sorting: ";
    for(int i=0;i<arr.size();i++)
    {
        cout<<arr[i]<<" ";
    }
    cout<<endl;
    sortArr(arr);
    cout<<"After Sorting: ";
    for(int i=0;i<arr.size();i++)
    {
        cout<<arr[i]<<" ";
    }
    return 0;
}
