//finds permutation of string
#include<iostream>
#include<string>
#include<algorithm>
using namespace std;
void getPermutation(string&str,int idx)
{
    if(idx==str.size())
    {
        cout << str << endl;
        return;
    }
    for(int i=idx;i<str.size();i++)
    {
        swap(str[idx],str[i]);
        getPermutation(str,idx+1);
        swap(str[idx],str[i]);
    }
}
int main()
{
    string str={"abc"};
    cout<<"The permutations are: "<<endl;
    getPermutation(str,0);
    return 0;
}