#include <bits/stdc++.h>
#define pb push_back
#define vi vector<int>
#define ll long long
#define vll vector<long long>
#define pll pair<ll,ll>
using namespace std;

int main() {
    int t;
    cin >> t;
    while(t--){
        ll n,c,q;
        string s;
        cin >> n >> c >> q;
        cin >> s;
        vector<pair<pll,pll>> ans;
        pair<pll,pll> init = {{1,n},{1,n}};
        ans.push_back(init);
        ll r = n;
        ll temp = c;
        while(temp--){
            ll a,b;
            cin >> a >> b;
            ll l = r+1;
            r = (b-a) + l;
            pair<pll,pll> new_interval = {{l,r},{a,b}};
            ans.push_back(new_interval);
        }
        while(q--){
            ll k;
            cin >> k;
            ll p=c;
            ll res=k;
            while(p>=0){
                if(ans[p].first.first<=res && ans[p].first.second>=res){
                    res = ans[p].second.first + (res-ans[p].first.first);
                }
                p--;
            }
            cout << s[res-1]<<'\n';
        }
    }
    return 0;
}
