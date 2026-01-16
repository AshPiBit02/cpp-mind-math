//Prints all the subsets of given array using recursion and backtracking(unique elements)
#include<iostream>
#include<vector>
using namespace std;
void getsubsets(vector<int>&arr,vector<int>&res,int i)
{
    if(i==arr.size())
    {
        cout<<"[ ";
        for(int val: res)
        {
            cout<<val<<" ";
        }
        cout<<"]"<<endl;
        return ;
    }
    res.push_back(arr[i]);//include elements to the subset
    getsubsets(arr,res,i+1);//inclusive call
    res.pop_back();
    getsubsets(arr,res,i+1);//exclusive call
}
int main()
{
    vector<int>arr={1,2,3};
    vector<int>res;
    getsubsets(arr,res,0);
    return 0;
}