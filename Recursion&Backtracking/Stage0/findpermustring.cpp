//finds permutation of string
#include<iostream>
#include<string>
#include<algorithm>
using namespace std;
void getPermutation(string&str,int idx)
{
    if(idx==str.size())
    {
        cout <<str<<endl;
        return;
    }
    for(int i=idx;i<str.size();i++)
    {
        swap(str[idx],str[i]);//placing ith index value at index idx
        getPermutation(str,idx+1);//recursive call
        swap(str[idx],str[i]);//backtarking (goes back to previously swaped position to form new combination)
    }
}
int main()
{
    string str={"abc"};
    cout<<"The permutations are: "<<endl;
    getPermutation(str,0);
    return 0;
}