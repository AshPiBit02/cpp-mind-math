//Find the first repeating element with both minimum and maximum index.
#include<iostream>
#include<unordered_map>
using namespace std;
int main()
{
    int arr[]={10,4,3,4,3,11,6};
    int n=sizeof(arr)/sizeof(arr[0]);
    unordered_map<int,int>firstIndex;//first int stores key other stores index of that key
    int min_idx=INT_MAX;
    for(int i=0;i<n;i++)
    {
        if(firstIndex.find(arr[i])!=firstIndex.end())//if element doesn't exits in map store current index as firrst occurance
        {
            min_idx=min(min_idx,firstIndex[arr[i]]);
        }
        else
        {
            firstIndex[arr[i]]=i;
        }
    }
    if(min_idx==INT_MAX)
    {
        cout<<"No repeating element!"<<endl;
    }else{
        cout<<"First repeating element is "<<arr[min_idx]<<endl;
    }
    return 0;

}
