#include <bits/stdc++.h>
#define pb push_back
#define vi vector<int>
#define ll long long
#define vll vector<long long>
#define pll pair<ll,ll>
using namespace std;
typedef std::tuple<int,int,int> mytuple;


#include <bits/stdc++.h>
#define pb push_back
#define vi vector<int>
#define ll long long

const int N = (2 * 1e5) + 1;
vector<int> adj[N];
ll dp[N];

ll dfs(int nd,int par){
    bool is_leaf = true;
    ll leafs = 0;
    for(auto son: adj[nd]){
        if(son==par) continue;
        is_leaf=false;
        leafs+=dfs(son,nd);
    }
    if (is_leaf){
        dp[nd]=1;
        return 1;
    }else{
        dp[nd]=leafs;
        return leafs;
    }
}


int main(){
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        for (int i = 0; i <= n; ++i) {
            adj[i].clear();
        }
        for (int i = 0; i < n-1; ++i) {
            int a,b;
            cin >> a >> b;
            adj[a].push_back(b);
            adj[b].push_back(a);
        }
        dfs(1,-1);
        int q;
        cin >> q;
        for (int i = 0; i < q; ++i) {
            int x,y;
            cin >> x >> y;
            cout << dp[x]*dp[y]<<'\n';
        }
    }
}