//Check if one string is valid anagram of other
#include<iostream>
#include<string>
#include<unordered_map>
using namespace std;
bool isAnagram(const string &str1,const string &str2)//const prevents from accidental modification
{
    if(str1.size()!=str2.size()) return false;//if size are different no chance of anagram
    unordered_map<char,int>freq;
    for(char c: str1)
    {
        freq[c]++;
    }
    for(char c: str2)
    {
        freq[c]--;
        if(freq[c]<0) return false;// which means that currenct c char occurs more in str2 than in str1 
    }
    for(auto &p: freq)
    {
        if(p.second!=0)//if str1 and str2 are anagrams then the value of each key(char) must be equal to zero
        {
            return false;
        }
    }
    return true;
}
int main()
{
    string str1="darkknight";
    string str2="nightdarkk";
    if(isAnagram(str1,str2))
    {
        cout<<"True"<<endl;
    }
    else
    {
        cout<<"False"<<endl;
    }
    return 0;
}
