// A Frog is at 0th stair and wants to reach the (n-1)th stair. The frog can jump to either the (i+1)th or (i+2)th stair from the ith stair. 
// However, there is a cost associated with each stair (height[i]). The cost of a jump is |height[i]-height[j]|. find the minimum total cost.
#include<iostream>
#include<cmath>
#include<vector>
#include<algorithm>
using namespace std;

int frogJump(int i,vector<int>&heights){
    if(i==0){
        return 0;
    }
    int left=frogJump(i-1,heights)+abs(heights[i]-heights[i-1]);
    int right=INT_MAX;
    if(i<1){
        right=frogJump(i-2,heights)+abs(heights[i]-heights[i-2]);
    }
    return min(left,right);
}

int main(){
    vector<int>heights={10,30,40,20};
    int n=heights.size();
    cout<<"Result: "<<frogJump(n-1,heights);
    return 0;
}
