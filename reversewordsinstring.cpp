//Reverse the words in a string
#include<iostream>
#include<string>
#include<algorithm>
using namespace std;
string reverse_string(string str)
{
    reverse(str.begin(),str.end());//Reverse the entire string
    int start=0;
    for(int i=0;i<=str.length();i++)
    {
        if(str[i]==' ' || i==str.length())
        {
            reverse(str.begin()+start,str.begin()+i);//reverse the each word in the string
            start=i+1;
        }
    }
    return str;
}
int main()
{
    string str="Virtual is Real";
    cout<<"The string before reversing: ";
    cout<<str<<endl;
    cout<<"The string after reversing: ";
    cout<<reverse_string(str)<<endl;
    return 0;
}
