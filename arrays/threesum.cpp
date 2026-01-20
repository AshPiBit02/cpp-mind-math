//find three element whose sum is equal to zero.(a+b+c=0)
#include<iostream>
#include<vector>
#include<set>
#include<algorithm>
using namespace std;
vector<vector<int>> threesum(vector<int>&arr)
{
    int n=arr.size();
    set<vector<int>>uniqueTriplest;
    for(int i=0;i<n;i++)
    {
        int target=-arr[i];// a+b=-c=target
        set<int>s;
        for(int j=i+1;j<n;j++)
        {
            int a=target-arr[j];//a=target-b;
            if(s.find(a)!=s.end())
            {
                vector<int>trip={arr[i],arr[j],a};
                // sort(trip.begin(),trip.end());
                uniqueTriplest.insert(trip);
                
            }
            s.insert(arr[j]);//insert b in set
        }
    }
    vector<vector<int>>ans(uniqueTriplest.begin(),uniqueTriplest.end());
    return ans;
}
int main()
{
    vector<int>arr={1,2,-4,-3,4,-1};
    vector<vector<int>>res=threesum(arr);
    cout<<"Triplets sum equal to zero are :"<<endl;
    for(int i=0;i<res.size();i++)
    {
        for(int j=0;j<res[i].size();j++)
        {
            cout<<res[i][j]<<" ";
        }
        cout<<endl;
    }
    cout<<endl;
    return 0;
}