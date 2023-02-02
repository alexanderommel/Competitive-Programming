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

    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        vll a;
        vllin(a,n);
        bool ans=true;
        ll l=0;
        ll r=LONG_LONG_MAX;
        fr(0,n-1,i){
            ll b = a[i];
            ll c = a[i+1]  ;
            if(b==c){
                continue;
            }
            ll d = (b+c)/2;
            if(b>c){
                if((b+c)%2!=0){
                    d++;
                }
                l=max(l,d);
                if(l>r){
                    ans=false;
                    break;
                }
            }else{
                r = min(r,d);
                if(l>r){
                    ans=false;
                    break;
                }
            }
        }
        if(ans){
            cout << l << '\n';
        }else{
            cout  << -1 << '\n';
        }
    }

    return 0;
}