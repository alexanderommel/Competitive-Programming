#include <bits/stdc++.h>
double PI = 3.14159265359;
using namespace std;
#define ll long long

const int N = 300001;
vector<int> g[N];
vector<int> sz(N);
vector<int> centroid;

void dfs(int n,int p, int nodes){
    sz[n]=1;
    bool is_centroid = true;
    for(auto c: g[n]){
        if (c==p) continue;
        dfs(c,n,nodes);
        sz[n]+=sz[c];
        if (sz[c]>nodes/2) is_centroid=false;
    }
    if (nodes - sz[n] > nodes/2) is_centroid = false;
    if (is_centroid) centroid.push_back(n);
}

int main(){
    int t; cin >> t;
    while(t--){
        int n; cin >> n;
        centroid.clear();
        for (int i = 0; i <= n; ++i) {
            g[i].clear();
        }
        for (int i = 0; i < n-1; ++i) {
            int a,b; cin >> a  >> b;
            g[a].push_back(b);
            g[b].push_back(a);
        }
        dfs(1,0,n);
        cout << "centroids\n";
        if (centroid.size()>1){
            cout << centroid[1]<<'\n';
        }
        cout << centroid[0]<<'\n';
    }
}