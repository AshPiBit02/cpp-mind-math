//Remove all occurrences
#include<iostream>
#include<string>
#include<vector>
using namespace std;
string removeoccurrences(string str,string part)
{
    while((str.find(part) < str.length()) && str.length()>0)
    if(str.find(part)<str.size())
    {
        str.erase(str.find(part),part.length());
    }
    return str;
}
int main()
{
    string str="aabcdcaabcbcdec";
    string part="abc";
    cout<<removeoccurrences(str,part);
    return 0;
}