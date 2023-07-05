#include <bits/stdc++.h>
#define ll long long
using namespace std;

const int N = 2 + 4*(1e5);
vector<ll> adj[N];
ll parents[N];


int main(){
    int t;
    cin >> t;
    while(t--){
        int a,b,k;
        cin >> a >> b >> k;
        for (int i = 1; i <= a ; ++i) {
            adj[i].clear();
        }
        for (int i = a+1; i <=a+b+1 ; ++i) {
            adj[i].clear();
            parents[i]=0;
        }
        ll c[k][2];
        for (int i = 0; i < k; ++i) {
            cin >> c[i][0];
        }
        for (int i = 0; i < k; ++i) {
            cin >> c[i][1];
            c[i][1]+=a;
        }
        for (int i = 0; i < k; ++i) {
            adj[c[i][0]].push_back(c[i][1]);
            parents[c[i][1]]+=1;
        }
        ll m=k;
        ll ans=0;
        for (int i = 1; i <=a ; ++i) {
            if (!adj[i].empty()){
                ll cont=0;
                for(auto child: adj[i]){
                    parents[child]-=1;
                    ll loc = m - (adj[i].size()-cont) - parents[child];
                    cont++;
                    m--;
                    ans+=loc;
                }
            }
        }
        cout << ans <<'\n';
    }
}