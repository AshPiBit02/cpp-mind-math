//Happy Number using set
#include<iostream>
#include<set>
using namespace std;
bool isHappy(int num)
{
    set<int>s;
    while(num!=1)
    {
        if(s.count(num))
        {
            return false;
        }
        s.insert(num);
        int sum=0;
        while(num>0)
        {
            int rem=num%10;
            sum+=rem*rem;
            num/=10;
        }
        num=sum;
    }
    return true;
}
int main()
{
    int num=37;
    if(isHappy(num))
    {
        cout<<"True"<<endl;
    }
    else
    {
        cout<<"False"<<endl;
    }
    return 0;

}