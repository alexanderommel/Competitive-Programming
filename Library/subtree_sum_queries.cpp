#include<bits/stdc++.h>
using namespace std;

#define ll long long

struct FenwickTree {
    vector<ll> bit;  // binary indexed tree
    int n;

    FenwickTree(int n) {
        this->n = n;
        bit.assign(n, 0);
    }

    ll sum(int r) {
        ll ret = 0;
        for (; r >= 0; r = (r & (r + 1)) - 1)
            ret += bit[r];
        return ret;
    }

    // inclusive interval
    ll sum(int l, int r) {
        return sum(r) - sum(l - 1);
    }

    void add(int idx, ll delta) {
        for (; idx < n; idx = idx | (idx + 1))
            bit[idx] += delta;
    }
};

const int N = 1e6;
ll tta[4][N];
map<int,ll> f;
vector<int> g[N];
int i = 0;

int dfs(int n, int parent){
    tta[0][n]=i;
    tta[1][i]=n;
    i++;
    int size = 1;
    for(auto c: g[n]){
        if (c==parent) continue;
        size+= dfs(c,n);
    }
    tta[2][tta[0][n]]=size;
    tta[3][tta[0][n]]=f[n];
    return size;
}


int main(){
    int n,q; cin >> n >> q;
    f.clear();
    i = 0;
    for (int i = 0; i < n+1; ++i) g[i].clear();
    for (int i = 1; i <= n; ++i) {
        ll val; cin >> val;
        f[i]=val;
    }
    for (int i = 0; i < n-1; ++i) {
        int a,b; cin >> a >> b;
        g[a].push_back(b);
        g[b].push_back(a);
    }
    dfs(1,0);
    FenwickTree bit = FenwickTree(n);
    for (int j = 0; j < n; ++j) {
        bit.add(j,tta[3][j]);
    }
    while(q--){
        int type; cin >> type;
        int s; cin >> s;
        int ix = tta[0][s];
        int end = ix + tta[2][ix]-1;
        int start = ix;
        if (type==1){
            int x; cin >> x;
            bit.add(ix,x-tta[3][ix]);
            tta[3][ix]=x;
        }else{
            cout << bit.sum(start,end)<<'\n';
        }
    }
}