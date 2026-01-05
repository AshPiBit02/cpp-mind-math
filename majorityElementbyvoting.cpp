//This program uses voting system to find the majority element(i.e. the frequency of one element in the array is greater than the half of size of array)
//initailly initailize the first element as majority element increase the vote count if next element is same else decrease the vote count
//when the value vote count becomes zero the updated majority element becomes the next index element and finally when the traversal get completed we get our majority element
#include<iostream>
using namespace std;
int main()
{
    int arr[]={7,7,5,7,5,1,2,7,7};
    int n=sizeof(arr)/sizeof(arr[0]);
    int voteCount=0,majorityEle=arr[0];
    for(int i=0;i<n;i++)
    {
        if(voteCount==0)
        {
            majorityEle=arr[i];
            voteCount=1;
        }
        else if(arr[i]==majorityEle)
        {
            voteCount++;
        }
        else
        {
            voteCount--;
        }
    }
    cout<<"Majority Element: "<<majorityEle<<endl;
    return 0;
}