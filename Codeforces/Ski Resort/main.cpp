#include <bits/stdc++.h>
#define pb push_back
#define vi vector<int>
#define ll long long
#define vll vector<long long>
#define pll pair<ll,ll>
using namespace std;
typedef std::tuple<int,int,int> mytuple;

int main(){
    int t;
    cin >> t;
    while(t--){
        ll n,k,q;
        cin >> n >> k >> q;
        vector<ll> sets;
        vector<ll> curr;
        for (int i = 0; i < n; ++i) {
            ll nm;
            cin >> nm;
            if (nm>q){
                if (curr.size()>0){
                    sets.push_back(curr.size());
                    curr.clear();
                }
            }else{
                curr.push_back(nm);
            }
        }
        if (curr.size()>0){
            sets.push_back(curr.size());
            curr.clear();
        }
        ll ans=0;
        for(auto st: sets){
            if (st>=k){
                ll hold = st - k + 1;
                ll pt = hold * (hold + 1);
                pt = pt / 2;
                ans+=pt;
            }
        }
        cout << ans <<'\n';
    }
}
