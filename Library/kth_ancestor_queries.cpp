#include<bits/stdc++.h>
using namespace std;

#define ll long long

const int N = 100001;
const int P = 17; // 1+LOG(N), 2eP > N
vector<int> g[N];
int DP[P][N];
vector<int> q={0};

void dfs(int n, int parent, int p, int d, int k){
    for(auto c: g[n]){
        if (c==parent) continue;
        q.push_back(n);
        DP[p][c]=q[max(0,d-k+1)];
        dfs(c,n,p,d+1,k);
        q.pop_back();
    }
}

int query(int n, int k){
    if (k==0) return n;
    int parent = n;
    int power = 1;
    int exp = 0;
    while (exp<P){
        power*=2;
        exp++;
    }
    while(k>0){
        if (power<=k){
            k-=power;
            parent = DP[exp][parent];
        }
        power/=2;
        exp--;
    }
    return parent;
}

int main(){
    int n; cin >> n;
    for (int i = 0; i < n+1; ++i) {
        for (int j = 0; j < P; ++j) DP[j][i]=0;
        g[i].clear();
    }
    for (int i = 0; i < n - 1; ++i) {
        int a,b; cin >> a >> b;
        g[a].push_back(b);
        g[b].push_back(a);
    }
    int exp = 0;
    int power = 1;
    while(exp<P){
        dfs(1,0,exp,1,power);
        power*=2;
        exp++;
    }
    cout << "-----------------queries---------------\n";
    int Q; cin >> Q;
    while(Q--){
        int node, kth; cin >> node >> kth;
        cout << query(node,kth)<<'\n';
    }
}