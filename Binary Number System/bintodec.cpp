//conversion of binary to decimal
#include<iostream>
using namespace std;
int bintodec(int bin)
{
    int pow=1,dec=0;
    while(bin>0)
    {
        int rem=bin%10;
        bin/=10;
        dec+=rem*pow;
        pow*=2;
    }
    return dec;
}
int main()
{
    cout<<bintodec(11111)<<endl;
    cout<<bintodec(10010)<<endl;
    cout<<bintodec(10101010)<<endl;
    cout<<1!<<endl;
    return 0;

}