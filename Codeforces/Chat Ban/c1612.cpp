#include <bits/stdc++.h>
#define pb push_back
#define vi vector<int>
#define ll long long
#define vll vector<long long>
#define fr(s,n,i) for (long long i=s; i<n; ++i)
#define fri(s,e,i) for (long long i=s; i>=e; --i)
#define len(arr) arr.size()
#define viin(vec,n) ff(n){int x; cin>>x; vec.pb(x);}
#define vllin(vec,n) ff(n){ll x; cin>>x; vec.pb(x);}
using namespace std;

ll f(ll n_msgs){
    if (n_msgs<=0)
        return 0;
    return n_msgs + ((n_msgs-1)*n_msgs)/2;
}

ll num_chars(ll k, ll n_msgs){
    ll num_chars = 0;
    if(n_msgs<=k){
        num_chars = f(n_msgs);
    }else{
        num_chars = f(k)+f(k-1)-f((2*k)-1-n_msgs);
    }
    return num_chars;
}

void sol(ll k, ll x){
    if (k==1){
        cout << 1 << '\n';
        return;
    }
    ll L=1;
    ll R=(2*k)-1;
    ll X=0;
    ll ANS= 2*k - 1;
    while(L<=R){
        X = (L+R)/2;
        ll chars = num_chars(k,X);
        if (chars<x){
            L=X+1;
        }else{
            R=X-1;
            ANS = min(ANS,X);
        }
    }
    cout << ANS << '\n';
}

int main(){
    int t;
    cin >> t;
    while(t--){
        ll k,x;
        cin >> k >> x;
        sol(k,x);
    }
}