#include <bits/stdc++.h>
#define pb push_back
#define vi vector<int>
#define ll long long
#define vll vector<long long>
#define fr(s,n,i) for (long long i=s; i<n; ++i)
#define fri(s,e,i) for (long long i=s; i>=e; --i)
#define len(arr) arr.size()
#define viin(vec,n) fr(0,n,i){int x; cin>>x; vec.pb(x);}
#define vllin(vec,n) fr(0,n,i){ll x; cin>>x; vec.pb(x);}
using namespace std;


int main(){
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);


    int n=100;
    int sieve[n+1];
    fr(0,n,i){
        sieve[i]=0;
    }

    fr(2,n+1,i){
        if(sieve[i]) continue;
        for(int j=2*i;j<=n;j+=i){
            sieve[j]=1;
        }
    }

    fr(1,n+1,i){
        cout << "Number " << i << " is " << ((sieve[i]) ? "not prime":"prime") << "\n";
    }


    return 0;
}