//This program rotates string right by k steps
#include<iostream>
#include<algorithm>
using namespace std;
 string rotate(string& str,int k)
{
    int n=str.length();
    k=k%n;//handles if k>n
    reverse(str.begin(),str.end());
    reverse(str.begin(),str.begin()+k);
    reverse(str.begin()+k,str.end());
    return str;
}
int main()
{
    int k=3;
    string str;
    cout<<"Enter a string: ";
    getline(cin,str);
    cout<<"The string after rotating to right by "<<k<<" steps is : "<<rotate(str,k)<<endl;
    return 0;
}