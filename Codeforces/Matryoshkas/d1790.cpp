#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define fr(s,n,i) for (long long i=s; i<n; ++i)
#define pb push_back
#define fri(s,e,i) for (long long i=s; i>=e; --i)
typedef std::priority_queue <ll, vector<ll>, greater<ll>> minqueue;

int main(){

    int t;
    cin >> t;
    minqueue  pq;
    while(t-- ){
        ll n;
        cin >> n;
        ll temp = n;
        vector<ll> vals;
        while(n--){
            ll nm;
            cin >> nm;
            vals.push_back(nm);
        }
        n = temp;
        std::sort(vals.begin(), vals.end());
        map<ll,ll> ans;
        fri(n-1,0,i){
            ans[vals[i]]--;
            ans[vals[i]-1]++;
        }
        ll ress=0;
        for(auto p: ans){
            if(p.second>0){
                ress+=p.second;
            }
        }
        cout <<ress<<'\n';
    }


}