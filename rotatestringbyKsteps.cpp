//This program rotates string right by k steps
#include<iostream>
#include<algorithm>
using namespace std;
int main()
{
    int k=3;
    string str;
    cout<<"Enter a string: ";
    getline(cin,str);
    reverse(str.begin(),str.end());
    reverse(str.begin(),str.begin()+k);
    reverse(str.begin()+k,str.end());
    cout<<"The string after rotating to right by "<<k<<" steps is : "<<str<<endl;
    return 0;


}