
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
typedef map<ll,ll, greater<ll>> desc_map;
typedef std::pair<ll,ll> mypair;
typedef std::priority_queue<ll> maxqueue;
typedef std::priority_queue <ll, vector<ll>, greater<ll>> minqueue;

ll up= 10e4 +1;

int main(){
    int t;
    cin >> t;
    while(t--){
        ll l,r,x;
        cin >> l >> r >> x;
        ll a,b;
        cin >> a >> b;


        r+=abs(l);a+=abs(l);b+=abs(l);l+=abs(l);

        int ans=INT_MAX;
        if(a>b){
            ll r2 = a + (b - l);
            ll l2 = b-(r - a);
            r = r2;
            l = l2;
            swap(a,b);
        }
        r+=abs(l);a+=abs(l);b+=abs(l);l+=abs(l);
        ll c;
        c=a;

        if(a==b){
            cout << 0 << '\n';
            continue;
        }

        if(a+x<=b){
            ans = min(ans,1);
        }else{
            if(a+x<=r){
                a=r;
                if(a-x>=b){
                    ans = min(ans,2);
                }else{
                    a=l;
                    if(a+x<=b){
                        ans = min(ans,3);
                    }
                }
            }
            a=c;
            if(a-x>=l){
                a=l;
                if(a+x<=b){
                    ans = min(ans,2);
                }else{
                    a=r;
                    if(a-x>=b){
                        ans = min(ans,3);
                    }
                }
            }
        }
        if(ans==INT_MAX){
            cout << -1 << '\n';
        }else{
            cout << ans << '\n';
        }
    }
}