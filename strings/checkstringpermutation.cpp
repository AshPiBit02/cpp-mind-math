//check if the str2 contains the permutation of the string present in str1
#include<iostream>
#include<string>
using namespace std;
bool isFreqSame(int freq[],int* windowfreq)//in function parameter int freq[] & int* freq both are same
{
    for(int i=0;i<26;i++)
    {
        if(freq[i]!=windowfreq[i])
        {
            return false;
        }
    }
    return true;

}
bool checkInclusion(string str1,string str2)
{
    int freq[26]={0};// stores frequencies of all characters
    for(int i=0;i<str1.length();i++)
    {
        freq[str1[i]-'a']++;//idx=str1[i]-'a' stores the frequency of str1 in frequency array
    }
    int windowSize=str1.length();//the windowsize will always be equal as the size of array whose permutation to be check. clearly
    for(int i=0;i<str2.length();i++)
    {
        int windowIdx=0,idx=i;
        int windFreq[26]={0};//windowFreq stores all frequency of the characters in current window
        while(windowIdx<windowSize && idx<str2.length())
        {
            windFreq[str2[idx]-'a']++;
            windowIdx++;
            idx++;
        }
        if(isFreqSame(freq,windFreq))
        {
            return true;
        }
    }
    return false;
}
int main()
{
    string str1="ab";
    string str2="edibaooo";
    if(checkInclusion(str1,str2))
    {
        cout<<"Permutation found..."<<endl;
    }
    else
    {
        cout<<"Permutation not found!"<<endl;
    }
    return 0;
}