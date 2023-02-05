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

typedef std::pair<ll,ll> mypair;
bool my_comparator ( const mypair& l, const mypair& r){
    return l.first > r.first;
}

int main(){
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    int t;
    cin >> t;
    while(t--){
        int n,m,x;
        cin >> n >> m >> x;
        priority_queue<pair<ll,int>> maxq;
        priority_queue <pair<ll,int>, vector<pair<ll,int>>, greater<pair<ll,int>>> minq;
        int ans[n];
        fr(0,n,i){
            ll nm;
            cin >> nm;
            maxq.push({nm,i});
        }
        fr(0,m,i){
            pair<ll,int> tp = maxq.top();
            minq.push({tp.first,i});
            maxq.pop();
            ans[tp.second]=i;
        }
        while(!maxq.empty()){
            pair<ll,int> tpmin = minq.top();
            pair<ll,int> tpmax = maxq.top();
            maxq.pop();
            minq.pop();
            ll newsz = tpmin.first + tpmax.first;
            ans[tpmax.second]=tpmin.second;
            minq.push({newsz,tpmin.second});
        }
        cout << "YES\n";
        fr(0,n,i){
            cout << ans[i] + 1 << " ";
        }
        cout << '\n';
    }

    return 0;
}
