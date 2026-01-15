//Three sum problem using two pointer approach
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
vector<vector<int>> threesum(vector<int>&arr)
{
    int n=arr.size();
    sort(arr.begin(),arr.end());
    vector<vector<int>>ans;
    for(int i=0;i<n;i++)
    {
        if(i>0 && arr[i]==arr[i-1]) continue;//handles redundency. skip the part in which the current i index element is equal to the previous one
        int j=i+1,k=n-1;//j points to the element next to i and k points to the end element;
        while(j<k)
        {
            int sum=arr[i]+arr[j]+arr[k];
            if(sum>0)
            {
                k--;//since k points to the large element
            }else if(sum<0)
            {
                j++;//since j points to the left element after i in the sorted array
            }else
            {
                ans.push_back({arr[i],arr[j],arr[k]});
                j++;k--;
                while(j<k && arr[j]==arr[j-1])//handles if the value at j repeats
                {
                    j++;
                }
                while(j<k && arr[k]==arr[k+1])//handles if the value at k repeats
                {
                    k--;
                }

            }
        }
    }
    return ans;
}
int main()
{
    vector<int>arr={-1,0,1,2,-1,-3};
    vector<vector<int>>res=threesum(arr);
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