//Two sum problem using unordered map
#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;
vector<int> twosum(vector<int>&arr,int target)
{
    unordered_map<int,int>m;
    vector<int>ans;
    for(int i=0;i<arr.size();i++)
    {
        int first=arr[i];//
        int sec=target-first;//first+second=target so ,second=target-first if any second equals to first then we get our pair
        if(m.find(sec)!=m.end())
        {
            ans.push_back(i);//pair's first element pushed to vector
            ans.push_back(m[sec]);//pari's second element pushed to vector
            break; 
        } 
        m[first]=i;//store first element(key) with its index(value ) in map
    }
    return ans;
}
int main()
{
    vector<int>arr={2,3,7,12,9,6};
    int target=13;
    vector<int>res=twosum(arr,target);
    if(!res.empty())
    {
        cout<<"Indices: "<<res[0]<<" and "<<res[1]<<endl;
    }else{
        cout<<"No pair found!"<<endl;
    }
    return 0;

}