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

int gcd(int a, int b){
    if(b==0)
        return a;
    return gcd(b,a%b);
}

int lcm(int a, int b){
    return (a*b)/(gcd(a,b));
}

int main(){
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    int a=30,b=12;

    cout << "GCD: "<<gcd(a,b) << '\n';
    cout << "LCM: " << (a*b)/(gcd(a,b)) << '\n';

    return 0;
}