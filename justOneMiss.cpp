//this pgram checks if there is exactly one missing number in a given range of integers
#include<iostream>
#include<string>
using namespace std;
int main()
{
    string arr[4]={"cati","cail","caiI","caer"};
    string target="cait";
    for(int i=0;i<4;i++)
    {
        if(arr[i].length()==target.length())
        {
            int count=0;
            for(int j=0;j<target.length();j++)
            {
            if(arr[i][j]!=target[j])
            {
                count++;
            }
            }
            if(count==1)
            {
                cout<<arr[i]<<endl;
            }
        }
    }
    return 0;
}