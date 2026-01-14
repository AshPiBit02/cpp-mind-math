//Container with most water problem where each elements of the array represent the height of a vertical line.
// we find which two vertical lines can store maximum water between them.
#include<iostream>
using namespace std;
int main()
{
    int arr[]={1,8,6,2,5,4,8,3,7};
    int n=sizeof(arr)/sizeof(arr[0]);
    int i=0, j=n-1, maxwater=0;
    
    while(i<j)
    {
        int height=min(arr[i],arr[j]);
        int water=height*(j-i);//j-i is the width between two lines
        maxwater=max(maxwater,water);
        
        if(arr[i]<arr[j])
            i++;
        else
            j--;
    }
    cout<<maxwater<<endl;
    return 0;
}