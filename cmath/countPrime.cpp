//Count number of prime numbers between given range
//using Sieve of Eratosthenes
//Time Complexity O(nloglogn)
#include<iostream>
#include<vector>
using namespace std;
int countPrime(int n)
{
    vector<bool>isPrime(n+1,true);//inialize all values as true i.e. as prime
    int count=0;
    for(int i=2;i<n;i++)
    {
        if(isPrime[i])
        {
            count++;
            for(int j=i*2;j<n;j=j+i)//for 2( 4,6,8,....) for 3(6,9,12,.....) ..... will become false
            {
                isPrime[j]=false;//if the next elements are the multiple of current prime number then they are not prime so mark them as false
            }
        }
    }
    return count;
}
int main()
{
    int n=26;
    cout<<countPrime(n)<<endl;
    return 0;
}