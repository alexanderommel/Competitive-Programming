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
    string s;
    int q;
    cin >> s >> q;
    int n = s.size();
    int S[n];
    fr(0,n-1,i){
        S[i] = (s[i]==s[i+1])?1:0;
    }
    int PS[n];
    if(s[n-2]==s[n-1]){
        S[n-1]=1;
    }
    PS[0]=0;
    fr(1,n,i){
        PS[i] = PS[i-1]+((S[i-1]==1)?1:0);
    }
    fr(0,q,i){
        int l,r;
        cin >> l >> r;
        int ans = PS[r-1] - PS[l-1];
        cout << ans << '\n';
    }
}