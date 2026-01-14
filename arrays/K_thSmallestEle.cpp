//This program find the K th smallest element of the array using priority queue
#include<iostream>
#include<queue>
using namespace std;
int main()
{
int arr[]={5,3,9,11,7,1,4};
int n=sizeof(arr)/sizeof(arr[0]),k=3;
priority_queue<int>pq;
for(int i=0;i<n;i++)
{
    pq.push(arr[i]);
    if(pq.size()>k)
    {
        pq.pop();
    }
}
cout<<pq.top()<<endl;
return 0;
}