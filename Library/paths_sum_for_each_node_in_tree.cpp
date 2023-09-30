#include <bits/stdc++.h>
double PI = 3.14159265359;
using namespace std;

/**
 * DISTANCE FROM NODE TO ALL NODES
 */

const int N = 100000 + 1;
bool visited[N];
vector<int> adj[N];
int DP[2][N];

void bfs(int n){
    visited[n]=true;
    int DPS = 0;
    int CS = 0;
    for(auto c: adj[n]){
        if (visited[c]) continue;
        bfs(c);
        CS+=DP[1][c];
        DPS+=DP[0][c];
        DP[1][n]++;
    }
    DP[0][n] = DP[1][n] + CS  + DPS;
    DP[1][n]+=CS;
}

void bfs2(int n){
    visited[n]=true;
    for(auto c: adj[n]){
        if (visited[c]) continue;
        int parent_children = DP[1][n]-DP[1][c]-1;
        DP[0][c]+=(DP[0][n]-DP[0][c]-DP[1][c]-1);
        DP[0][c]+=parent_children;
        DP[1][c]+=parent_children+1;
        bfs2(c);
    }
}

int main(){
    int n; cin >> n;
    for (int i = 0; i < n + 1; ++i) {
        DP[0][i]=0;
        DP[1][i]=0;
        visited[i]= false;
        adj[i].clear();
    }
    for (int i = 0; i < n-1; ++i) {
        int a,b; cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    bfs(1);
    for (int i = 0; i < n + 1; ++i) {
        visited[i]=false;
        cout << DP[0][i]<<" ";
    }
    DP[0][0]=DP[0][1]+DP[1][1];
    DP[1][0]=1;
    bfs2(1);
    cout << '\n';
    for (int i = 0; i < n + 1; ++i) {
        visited[i]=false;
        cout << DP[0][i]<<" ";
    }

}