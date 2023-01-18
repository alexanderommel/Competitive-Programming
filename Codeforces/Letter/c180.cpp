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

vector<pair<int,int>> M;

int main(){

    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    string s;
    cin >> s;

    int n = s.size();

    int L[n];
    int U[n];
    fr(0,n,i){
        L[i]=0;
        U[i]=0;
    }
    int lowers=0;
    fr(0,n,i){
        L[i]=lowers;
        if (s[i]>='a'){
            lowers++;
        }
    }
    int highers=0;
    fri(n-1,0,i){
        U[i]=highers;
        if (s[i]<'a'){
            highers++;
        }
    }
    int ans = INT_MAX;
    fr(0,n,i){
        ans = min(ans,L[i]+U[i]);
    }
    cout << ans << '\n';

}

