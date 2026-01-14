//String compress
#include<iostream>
#include<string>
#include<vector>
using namespace std;

int compress(vector<char>&chars)
{
    int n=chars.size();
    int idx=0;
    for(int i=0;i<n;)
    {
        char ch=chars[i];
        int count=0;
        while(i<n && chars[i]==ch)
        {
            count++; i++;
        } 
        if(count==1)// if a only occurs once then we don't need to write a1, we simply write a
        {
            chars[idx++]=ch;
        }
        else
        {
            chars[idx++]=ch;
            string str=to_string(count);
            for(char dig:str)
            {
                chars[idx++]=dig;
            }
        }
    }
    chars.resize(idx);
    return idx;
}
int main()
{
    vector<char>chars={'a','a','b','b','b','c','c','c'};//a 2 b 3 c 2
    cout<<"Before compression: ";
    for(char i: chars)
    {
        cout<<i<<" ";
    }
    cout<<"|  size: "<<chars.size();
    compress(chars);
    cout<<"\nAfter compression: ";
    for(char i:chars)
    {
        cout<<i<<" ";
    }
    cout<<"|  size: "<<compress(chars);
    return 0;
}
