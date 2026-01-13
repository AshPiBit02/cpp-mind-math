#include<iostream>
using namespace std;
int Isvalidpalindrome(string &str)
{
    int start=0,end=str.size()-1;
    while(start<end && true)
    {
        if(isalnum(str[start]) && isalnum(str[end]))
        {
            return tolower(str[start++])==tolower(str[end--]);
        }
        else if(!isalnum(str[start++]))
        {
        }
        else
        {
            end--;
        }
    }
}
int main()
{
    string str="Ac3?e3c&a";
    cout<<Isvalidpalindrome(str);
    return 0;
}