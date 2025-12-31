//This program checks if sum any two elements of the array equal to the target value 
#include<iostream>
#include<algorithm>
using namespace std;
int sum(int a,int b)
{
    return a+b;
}
int main()
{
    int a[]={2,11,15,5,7};
    int n=sizeof(a)/4;
    sort(a,a+n);
    int val=18,i=0,j=n-1;
    while(i<j)
    {
        if(sum(a[i],a[j])==val)
        {
            cout<<"The elements are at indexes :"<<i<<" & "<<j<<endl;
            break;
        }
        else if(sum(a[i],a[j])<val)
        {
            i++;
        }
        else
        {
            j--;
        }
    }
    if(sum(a[i],a[j])!=val)
    {
        cout<<"There are no such elements in the array!"<<endl;
    }
    return 0;
}