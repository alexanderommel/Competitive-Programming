#include<bits/stdc++.h>
using namespace std;

#define ll long long


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
    int n; cin >> n;
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
    for (int j = 0; j < 4; ++j) {
        for (int k = 0; k < n; ++k) {
            cout << tta[j][k] <<" ";
        }
        cout << '\n';
    }

}
