#include <bits/stdc++.h>
#define ll long long
using namespace std;

const int th = 40001;

int main(){
    ll n, k;
    cin >> n >> k;
    vector<pair<ll,ll>> a(n);
    vector<pair<ll,ll>> c(n);
    for (int i = 0; i < n; ++i) {
        a[i]={0,0};
    }
    for (int i = 0; i < n; ++i) {
        cin >> a[i].first;
        c[i]={a[i].first,i};
    }
    for (int i = 0; i < n; ++i) {
        cin >> a[i].second;
    }
    ll ans[n];
    for (int i = 0; i < n; ++i) {
        ans[i]=0;
    }
    std::sort(c.begin(), c.end());
    std::sort(a.begin(), a.end());
    priority_queue<ll> pq;
    ll sz = 0;
    for (int i = 0; i < n; ++i) {
        ll d = 0;
        ans[c[i].second]+=a[i].second;
        vector<ll> rm;
        while(d<min(sz,k)){
            ll nm = pq.top();
            rm.push_back(nm);
            pq.pop();
            d++;
        }
        for (int j = 0; j < rm.size(); ++j) {
            ans[c[i].second]+=rm[j];
        }
        for (int j = 0; j < rm.size(); ++j) {
            pq.push(rm[j]);
        }
        pq.push(a[i].second);
        sz++;
    }
    for (int i = 0; i < n; ++i) {
        cout << ans[i]<<" ";
    }
    cout <<'\n';
}
