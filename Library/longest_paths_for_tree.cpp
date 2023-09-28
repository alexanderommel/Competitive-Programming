#include <bits/stdc++.h>
double PI = 3.14159265359;
using namespace std;

/**
 * ALL LONGEST PATHS FOR A UNDIRECTED TREE OF N-1 EDGES
 * THIS CODE COMPUTES THE LONGEST PATH FOR EACH NODE IN THE TREE
 */

const int N = 100 + 1;
bool visited[N];
vector<int> adj[N];
int DP[4][N];

// STEP 1: Use the children nodes to compute the parents initial value
int bfs1(int n){
    visited[n]=true;
    vector<pair<int,int>> max_paths(max(2,static_cast<int>(adj[n].size())),{0,n});
    max_paths[0]={0,n};
    max_paths[1]={0,n};
    int i = -1;
    for(auto c: adj[n]){
        i++;
        if (visited[c]) continue;
        int my_son_path = 1+bfs1(c);
        max_paths[i]={my_son_path,c};
    }
    std::sort(max_paths.begin(), max_paths.end());
    std::reverse(max_paths.begin(), max_paths.end());
    DP[0][n]=max_paths[0].first;
    DP[1][n]=max_paths[0].second;
    DP[2][n]=max_paths[1].first;
    DP[3][n]=max_paths[1].second;
    return DP[0][n];
}

// Use parents to update children nodes value
void bfs2(int n, int parent){
    visited[n]=true;
    vector<pair<int,int>> winners;
    winners.emplace_back(DP[0][n],DP[1][n]);
    winners.emplace_back(DP[2][n],DP[3][n]);
    if (DP[1][parent]!=n) winners.emplace_back(1+DP[0][parent],parent);
    if (DP[3][parent]!=n) winners.emplace_back(1+DP[2][parent],parent);
    std::sort(winners.begin(), winners.end());
    std::reverse(winners.begin(), winners.end());
    DP[0][n]=winners[0].first;
    DP[1][n]=winners[0].second;
    DP[2][n]=winners[1].first;
    DP[3][n]=winners[1].second;
    for(auto c: adj[n]){
        if (visited[c]) continue;
        bfs2(c,n);
    }
}


int main(){
    int n; cin >> n;
    DP[0][0]=0;
    DP[1][0]=1;
    DP[2][0]=0;
    DP[3][0]=1;
    for (int i = 0; i < n + 1; ++i) {
        visited[i]= false;
    }
    for (int i = 0; i < n-1; ++i) {
        int a,b; cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    bfs1(1);
    for (int i = 0; i < n + 1; ++i) {
        visited[i]= false;
    }
    bfs2(1,0);
    for (int i = 0; i < n+1; ++i) {
        cout << DP[0][i]<<" ";
    }
}