//Conversion of decimal to binary
#include<iostream>
using namespace std;
int decimaltobin(int dec)
{
    int bin=0,pow=1;
    while(dec!=0)
    {
        int 
        rem=dec%2;
        dec/=2;
        bin+=rem*pow;
        pow*=10;
    }
    return bin;

}
int main()
{
    for(int i=0;i<12;i++)
    {
         cout<<i<<"  :  "<<decimaltobin(i)<<endl;
    }
    return 0;
}