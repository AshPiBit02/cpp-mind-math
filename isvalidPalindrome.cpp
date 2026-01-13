//Program to check if the string is valid palindrome
#include<iostream>
using namespace std;
bool isAlnum(char ch)
{
    if((ch>='0' && ch<='9') || (tolower(ch)>='a' && tolower(ch)<='z'))
    {
        return true;
    }else
    {
        return false;
    }
}
int Isvalidpalindrome(string &str)
{
    int start=0,end=str.size()-1;
    while(start<end && true)
    {
        if(isAlnum(str[start]) && isalnum(str[end]))//if both are alpha numeric
        {
            return tolower(str[start++])==tolower(str[end--]);//assume that both lower and upper case are sameg
        }
        else if(!isAlnum(str[start++]))//if start is not alpha numeric
        {
        }
        else//if end is not alpha numeric
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