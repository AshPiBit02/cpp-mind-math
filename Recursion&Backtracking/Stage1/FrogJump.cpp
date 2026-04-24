// A Frog is at 0th stair and wants to reach the (n-1)th stair. The frog can jump to either the (i+1)th or (i+2)th stair from the ith stair. 
// However, there is a cost associated with each stair (height[i]). The cost of a jump is |height[i]-height[j]|. find the minimum total cost.
#include<iostream>
#include<cmath> //contains abs()
#include<vector>
#include<algorithm> //contains min()
#include<climits>
using namespace std;

int frogJump(int i,vector<int>&heights,vector<int>&dp){
    if(i==0){
        return 0;
    }
    if(dp[i]!=-1){
        return dp[i];
    }
    int left=frogJump(i-1,heights,dp)+abs(heights[i]-heights[i-1]);
    int right=INT_MAX;
    if(i>1){
        right=frogJump(i-2,heights,dp)+abs(heights[i]-heights[i-2]);
    }
    return dp[i]=min(left,right);
}

int main(){
    vector<int>heights={10,30,40,20,25,45};
    int n=heights.size();
    vector<int>dp(n,-1);
    cout<<"Result: "<<frogJump(n-1,heights,dp);
    return 0;
}
