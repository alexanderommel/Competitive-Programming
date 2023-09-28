#include <bits/stdc++.h>
#define ll long long
using namespace std;

const int N = 220005;
vector<int> adj[N];
bool visited[N];
int parent[N];
int sizes[N];
int colors[N];
bool ans;

void make_set(int v) {
    parent[v] = v;
    sizes[v] = 1;
}

int find_set(int v) {
    if (v == parent[v])
        return v;
    return find_set(parent[v]);
}

void union_sets(int a, int b) {
    a = find_set(a);
    b = find_set(b);
    if (a != b) {
        if (sizes[a] < sizes[b])
            swap(a, b);
        parent[b] = a;
        sizes[a] += sizes[b];
    }
}

void bfs(int n,int color){
    //cout << "my color is: "<<color<<'\n';
    if (visited[n]) return;
    visited[n]=true;
    int new_color;
    if (color==1) new_color=0;
    else new_color=1;
    for(auto p: adj[n]){
        //cout << "my child "<<p<<" will have the color: "<<new_color<<'\n';
        if (colors[p]==color) ans=false;
        colors[p]=new_color;
        bfs(p,new_color);
    }
}


int main(){
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        ans=true;
        map<int,int> f;
        map<string ,pair<int,int>> h;
        for (int i = 0; i < n; ++i) {
            int a,b;
            cin >> a >> b;
            if (b>a) swap(a,b);
            f[a]++;
            f[b]++;
            if (a==b || f[a]>=3 || f[b]>=3) ans=false;
            string rep = to_string(a)+"-"+ to_string(b);
            h[rep]={a,b};
        }
        if (!ans){
            cout << "NO\n";
            continue;
        }
        for(auto p: f){
            make_set(p.first);
            adj[p.first].clear();
            visited[p.first]=false;
            colors[p.first]=-1;
        }
        for(auto p: h){
            int a = p.second.first;
            int b = p.second.second;
            union_sets(a,b);
            adj[a].push_back(b);
            adj[b].push_back(a);
        }
        map<int,int> parents;
        for(auto p: f){
            int par = find_set(p.first);
            parents[par]++;
        }
        for(auto p: parents){
            colors[p.first]=1;
            bfs(p.first,1);
        }
        if (ans){
            cout << "YES\n";
        }else{
            cout  << "NO\n";
        }
    }
}