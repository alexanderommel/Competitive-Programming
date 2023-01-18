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

    int n; string s;
    cin >> n; cin >> s;
    map<int,pair<ll,ll>> ANS;
    ll minim=0;
    for(ll i=0, ones=0, zeros=0 ;i<n;i++){
        (s[i]=='1')?ones++:zeros++;
        int diff = ones - zeros;
        if (diff==0) minim = max(minim, i + 1);
        if (ANS.count(diff)>0){
            pair<int,int> curr = ANS[diff];
            ANS[diff]={curr.first,i};
            minim = max(minim,i-curr.first);
        }else{
            ANS[diff]={i,-1};
        }
    }

    cout << minim << '\n';

    return 0;
}