//find the missing and repeated values in 2D array of size n to n*n
#include<iostream>
#include<vector>
#include<unordered_set>
using namespace std;
vector<int> missingrepeating(vector<vector<int>>&arr)
{
    vector<int>ans;
    unordered_set<int>s;
    int n=arr.size();
    int a,b;//a for repeating and for missing
    int acutalsum=0;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            acutalsum+=arr[i][j];
            if(s.find(arr[i][j])!=s.end())
            {
                a=arr[i][j];
                ans.push_back(a);
            }
            s.insert(arr[i][j]);
        }
    }
    int expectedSum=(n*n)*(n*n +1)/2;
    //expectedsum=acutalsum+missing number-repeated number
    b=expectedSum+a-acutalsum;//since be came in actual sum instead of a
    ans.push_back(b);
    return ans;
}
int main()
{
    vector<vector<int>>arr={{9,1,7},{8,9,2},{3,4,6}};
    vector<int>res=missingrepeating(arr);
    if(!arr.empty())
    {
        cout<<"Repeating element: "<<res[0]<<"\nMissing element: "<<res[1]<<endl;
    }
    else
    {
        cout<<"Not found!"<<endl;
    }
    return 0;
}
