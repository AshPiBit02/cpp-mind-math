//Find the next permutation of the given array;
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
void nextpermutation(vector<int>&arr)
{
    int n=arr.size()-1;
    int pivot=n;
    do{
        pivot--;
        if(arr[pivot]<arr[n])
        {
            n=-1;
        }
        n--;

    }while(n>=0);
    swap(arr[pivot],arr[arr.size()-1]);
    reverse(arr.begin()+3,arr.end());
}
int main()
{
    vector<int>arr={1,2,3,6,5,4};
    nextpermutation(arr);
    cout<<"The next permutation is : ";
    for(int i:arr)
    {
        cout<<i<<" ";
    }
    cout<<endl;
    return 0;
}