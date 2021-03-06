#include <iostream>
#include <math.h>
#include <vector>

using namespace std;

/*
A positive integer, n, is factorised into prime factors. We define f(n) to be the product when each prime factor is replaced with 2. In addition we define f(1)=1.

For example, 90=2×3×3×5, then replacing the primes, 2×2×2×2=16, hence f(90)=16.

Let S(N)=∑(1,N,f(n)). You are given S(10^8)=9613563919.

Find S(10^14).
*/

vector<long long> primeFactorCount(long long);
long long f(long long);
long long S(long long);

int main(){
    //cout<<"S(10^8) = "<<S(pow(10,8))<<endl;
    cout<<"S(10^14) = "<<S(pow(10,14))<<endl;
}

vector<long long> primeFactorCount(long long n){
    vector<long long> primeFactors;

    while (n%2 == 0){
        primeFactors.push_back(2);
        n = n/2;
    }
    for (long long i = 3; i <= sqrt(n); i = i+2){
        while (n%i == 0){
            primeFactors.push_back(i);
            n = n/i;
        }
    }
    if (n > 2){
        primeFactors.push_back(n);
    }

    return primeFactors;
}

long long f(long long n){
    if (n == 1) {
        return 1;
    }else{
        long long val = 0;
        long long pFCount = primeFactorCount(n).size();
        if(pFCount == 1){ val = 2; }
        else if (pFCount == 2) { val = 4; }
        else if (pFCount == 3) { val = 8; }
        else if (pFCount == 4) { val = 16; }
        else if (pFCount == 5) { val = 32; }
        else if (pFCount == 6) { val = 64; }
        else { val = pow(2, primeFactorCount(n).size()); }

        //cout<<val<<endl;
        return val;
    }
}

long long S(long long N){
    long long total = 0;

    for(long long n = 1; n <= N; n++){
        total += f(n);
        //cout<<total<<endl;
    }

    return total;
}