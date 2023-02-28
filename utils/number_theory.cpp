#include <bits/stdc++.h>
using namespace std;

int gcd(int a, int b){
    if(b==0)
        return a;
    return gcd(b,a%b);
}

int lcm(int a, int b){
    return (a*b)/(gcd(a,b));
}

int sieve_of_eratosthenes(){
    int n=100;
    int sieve[n+1];
    for(int i=0;i<n;++i){
        sieve[i]=0;
    }
    for(int i=2;i<=n;++i){
        if(sieve[i]) continue;
        for(int j=2*i;j<=n;j+=i){
            sieve[j]=1;
        }
    }
}