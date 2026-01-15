//Find the unique combination of four element such that their sum equal to the target
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
vector<vector<int>> foursum(vector<int>&arr,int target)
{
    int n=arr.size();
    vector<vector<int>>ans;
    sort(arr.begin(),arr.end());//to use two pointer approach we first have to sort
    for(int i=0;i<n;i++)
    {
        if(i>0 && arr[i]==arr[i-1]) continue;
        for(int j=i+1;j<n;j++)
        {
            if(j>i+1 && arr[j]==arr[j-1]) continue;
            int k=j+1,l=n-1;
            while(k<l)
            {
                int sum=arr[i]+arr[j]+arr[k]+arr[l];
                if(sum<target)//shift k to the right so k points to slight larger value
                {
                    k++;
                }else if(sum>target)//shift l to left so l points to slight smaller value
                {
                    l--;
                }else
                {
                    ans.push_back({arr[i],arr[j],arr[k],arr[l]});
                    k++;l--;
                    while(k<l && arr[l]==arr[l+1]) l--;//handles if same value to the left index comes
                    while(k<l && arr[k]==arr[k-1]) k++;//handles if smae value to the right index comes
                }
            }

        }
    }
    return ans;
}
int main()
{
    vector<int>arr={-2,-1,-1,1,1,2,2};
    int target=0;
    vector<vector<int>>res=foursum(arr,target);
    cout<<"The four pair/s: "<<endl;
    for(int i=0;i<res.size();i++)
    {
        for(int j=0;j<res[i].size();j++)
        {
            cout<<res[i][j]<<" ";
        }
        cout<<endl;
    }
    return 0;
}
