#include<iostream>
using namespace std;
void swap(int &a,int &b)
{
  b=a+b-(a=b);// a=20 b=10+20-20=10;
}
int main()
{
  int a=10,b=20;
  cout<<"Before Swapping: a = "<<a<<" & b is "<<b<<endl; 
  swap(a,b);
  cout<<"Before Swapping: a = "<<a<<" & b is "<<b<<endl; 
  return 0;
}
