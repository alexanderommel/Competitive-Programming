#include <bits/stdc++.h>
using namespace std;
#define ll long long int

ll gcd(ll a, ll b){
    if(b==0)
        return a;
    return gcd(b,a%b);
}

ll lcm(ll a, ll b){
    return (a*b)/(gcd(a,b));
}

ll sieve_of_eratosthenes(){
    int n=100;
    ll sieve[n+1];
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

/** Descomposición prima sin repetición **/

void unique_prime_factors_of_n(long long n) {
    map<long long,long long> f;
    for (long long x = 2; x*x <= n; x++) {
        while (n%x == 0) {
            if(f.count(x)<1){
                f[x]++;
            }
            n /= x;
        }
    }
    if (n > 1){
        f[n]++;
    }
}

/** Algoritmo de Miller Rabin para determinar si un número es probable primo **/
long long binpower(long long base, long long e, long long mod) {
    long long result = 1;
    base %= mod;
    while (e) {
        if (e & 1)
            result = (long long)result * base % mod;
        base = (long long)base * base % mod;
        e >>= 1;
    }
    return result;
}

bool check_composite(long long n, long long a, long long d, int s) {
    long long x = binpower(a, d, n);
    if (x == 1 || x == n - 1)
        return false;
    for (int r = 1; r < s; r++) {
        x = (long long)x * x % n;
        if (x == n - 1)
            return false;
    }
    return true;
};

bool MillerRabin(long long n, int iter=5) { // returns true if n is probably prime
    if (n < 4)
        return n == 2 || n == 3;

    int s = 0;
    long long d = n - 1;
    while ((d & 1) == 0) {
        d >>= 1;
        s++;
    }

    for (long long i = 0; i < iter; i++) {
        int a = 2 + rand() % (n - 3);
        if (check_composite(n, a, d, s))
            return false;
    }
    return true;
}
