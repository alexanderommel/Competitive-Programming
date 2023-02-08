#include <bits/stdc++.h>
#define pb push_back
#define vi vector<int>
#define ll long long
#define vll vector<long long>
#define fr(s,n,i) for (long long i=s; i<n; ++i)
#define fri(s,e,i) for (long long i=s; i>=e; --i)
#define len(arr) arr.size()
#define viin(vec,n) fr(0,n,i){int x; cin>>x; vec.pb(x);}
#define vllin(vec,n) fr(0,n,i){ll x; cin>>x; vec.pb(x);}
#define LSB(i)  ((i) & -(i))

using namespace std;
typedef map<ll,ll, greater<ll>> desc_map;
typedef std::pair<ll,ll> mypair;
typedef std::priority_queue<ll> maxqueue;
typedef std::priority_queue <ll, vector<ll>, greater<ll>> minqueue;

const int N= 10e5 + 1;
vector<int> adj[N];
bool visited[N];
bool no_ans=false;
map<string,int> cp;

void dfs(int p, int init){
    visited[p]=true;
    if(adj[p].size()>2){
        no_ans=true;
        return;
    }
    int weight = init;
    for(auto node: adj[p]){
        if(visited[node]) continue;
        if(no_ans) return;
        if(weight==2){
            weight = 3;
        }else{
            weight = 2;
        }
        string key1 = to_string(p) + "-" + to_string(node);
        string key2 = to_string(node) + "-" + to_string(p);
        cp[key1]=weight;
        cp[key2]=weight;
        dfs(node,weight);
    }
}

int main(){
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        no_ans = false;
        vector<string> queries;
        vector<pair<int,int>> edges;
        fr(0,n-1,i){
            int u,v;
            cin >> u >> v;
            string key1 = to_string(u) + "-" + to_string(v);
            cp[key1]=0;
            queries.push_back(key1);
            edges.pb({u,v});
            adj[u].clear();
            adj[v].clear();
            visited[u]=false;
            visited[v]=false;
        }
        fr(0,n-1,i){
            pair<int,int> edge = edges[i];
            int son = max(edge.first,edge.second);
            int parent = min(edge.first,edge.second);
            adj[parent].push_back(son);
            adj[son].push_back(parent);
        }
        dfs(1,2);
        if(no_ans){
            cout << -1 <<'\n';
        }else{
            fr(0,n-1,j){
                cout << cp[queries[j]] << " ";
            }
            cout << '\n';
        }
    }
}