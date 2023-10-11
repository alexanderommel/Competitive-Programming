#include <bits/stdc++.h>
double PI = 3.14159265359;
using namespace std;
#define ll long long

/**
 * ALL LONGEST PATHS FOR A UNDIRECTED TREE OF N-1 EDGES
 * THIS CODE COMPUTES THE LONGEST PATH FOR EACH NODE IN THE TREE
 */

const int N = 200001;

vector<int> g[N];
ll in[N], out[N];

// search childs
ll dfs1(int n, int p){
    in[n]=0LL;
    for(auto c: g[n]){
        if (c==p) continue;
        dfs1(c,n);
        in[n] = max(in[n],1+in[c]);
    }
}

// search on parent
ll dfs2(int n, int p){
    ll mx1 = -1;
    ll mx2 = -1;
    for(auto c: g[n]){
        if (c==p) continue;
        if (in[c]>=mx1) mx2 = mx1, mx1 = in[c];
        else if (in[c]>mx2) mx2 = in[c];
    }
    for(auto c: g[n]){
        if (c==p) continue;
        ll use = mx1;
        if (mx1 == in[c]) use = mx2;
        out[c] = max(1LL + out[n],2LL + use);
        dfs2(c,n);
    }
}

int main(){

    int t; cin >> t;
    while(t--){
        int n; long long k,c; cin >> n >> k >> c;
        for (int i = 0; i < n + 1; ++i) {
            g[i].clear();
            in[i]=0;
            out[i]=0;
        }
        for (int i = 0; i < n-1; ++i) {
            int a,b; cin >> a >> b;
            g[a].push_back(b);
            g[b].push_back(a);
        }
        dfs1(1,0);
        dfs2(1,0);
        ll ans = 0;
        for (int i = 1; i <=n ; ++i) {
            ll max_distance = max(in[i],out[i]);
            ans = max(ans,max_distance);
        }
        cout << ans <<'\n';
    }
}