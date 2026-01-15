//Find duplicate element in the array using fast and slow pointer
#include<iostream>
#include<vector>
using namespace std;
int finduplicate(const vector<int>&arr)
{
    int slow=arr[0],fast=arr[0];
    do
    {
        slow=arr[slow];//+1
        fast=arr[arr[fast]];//+2
    } while (slow!=fast);
    slow=arr[0];
    while(slow!=fast)
    {
        slow=arr[slow];//+1
        fast=arr[fast];//+1
    }
    return slow;
}
int main()
{
    vector<int>arr={2,4,3,1,5,4};//value elements in the array must be less than the size of array
    cout<<"Duplicate : "<<finduplicate(arr);
    return 0;
}