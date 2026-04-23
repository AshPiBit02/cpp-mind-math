// Problem to count ways to Reach Nth stair 
#include<iostream>
using namespace std;

int ways(int n){
    if(n==1){
        return 1;
    }
    else if(n==2){
        return 2;
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
