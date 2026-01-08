// Given two strings str1 and str2, determine if str2 is a subsequence of str1.
// A subsequence means all characters of str2 appear in str1 in the same order,
// but not necessarily contiguously.
#include<iostream>
#include<string>
using namespace std;
int main() {
    string str1 ="ahcdbgcd";
    string str2 ="abc";
    int j=0;

    for (int i=0;i<str1.size() && j<str2.size();i++) {
        if (str1[i]==str2[j]) {
            j++;
        }
    }

    cout<<((j==str2.size())?"Is Subsequence":"Is not Subsequence");
    return 0;
}