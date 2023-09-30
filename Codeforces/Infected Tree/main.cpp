#include <bits/stdc++.h>
#define ll long long
using namespace std;

const int N = 300001;
vector<int> adj[N];
bool visited[N];

int bfs(int n, int add){
    if (visited[n]) return 0;
    visited[n]=true;
    int i = 0;
    int childs[2];
    for(auto c: adj[n]){
        if (visited[c]) continue;
        childs[i]=c;
        i++;
    }
    if (i==0) return add;
    if (i==1) return add+1;
    int ka = bfs(childs[0],add+2);
    int kb = bfs(childs[1],add+2);
    return min(ka,kb);
}

int main(){
    int t;
    cin >> t;
    while (t--){
        int n;
        cin >> n;
        for (int i = 0; i < n-1; ++i) {
            adj[i+1].clear();
            visited[i+1]=false;
        }
        adj[n].clear();
        visited[n]=false;
        for (int i = 0; i < n-1; ++i) {
            int a,b;
            cin >> a >> b;
            adj[a].push_back(b);
            adj[b].push_back(a);
        }
        if(n<3){
            cout << 0 <<'\n';
            continue;
        }
        int rest = bfs(1,0);
        int remainder = n - rest - 1;
        cout << remainder <<'\n';
    }
}