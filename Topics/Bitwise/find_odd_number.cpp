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

/**
 * Given a set of numbers where all elements occur an even number of times except one number, find the odd occurring number
 * **/

int main(){
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    int a[] = { 12, 12, 14, 90, 14, 14, 14 };
    int n = sizeof(a) / sizeof(a[0]);

    /**
     * Since there's some even frequency numbers, they all will become 0 except the odd number
     * **/

    int odd;
    fr(0,n,i){
        odd^=a[i];
    }

    cout << odd;

    return 0;
}

