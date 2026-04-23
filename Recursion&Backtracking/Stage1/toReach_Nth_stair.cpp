// Problem to count ways to Reach Nth stair 
#include<iostream>
using namespace std;

int ways(int n){
    if(1==n || 2==n){
        return n;
    }
    return ways(n-1)+ways(n-2);
}


int main(){
    int n;
    cout<<"Enter number of stairs:";
    cin>>n;
    int result=ways(n);
    cout<<"No of ways to reach "<<n<<" stair(s) is "<<result;

    return 0;
}
