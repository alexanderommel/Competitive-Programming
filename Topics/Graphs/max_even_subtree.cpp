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
using namespace std;

 const int N=7;
vi adj[N+1];
int W[]={1,2,6,4,2,0,3};

int num_sets=N; int max_size=1;
vector<int> parent, sz;


void init(int n){
    parent = vector<int>(n+1,0);
    sz = vector<int>(n+1,0);
    for(int i=1;i <=n; i++){
        parent[i]=i;
        sz[i]=1;
    }
    num_sets = n;
    max_size=1;
}
void make_set(int e){parent[e]=e;}
int find_representative(int e){
    while(e!=parent[e]){parent[e]=parent[parent[e]]; e = parent[e];}return e;
}
void union_set(int u,int v){
    int a = find_representative(u); int b = find_representative(v);
    if(a==b){ return; }
    num_sets--;
    if(sz[a]>sz[b]){swap(a,b);}
    sz[b]+=sz[a];
    sz[a]=0;
    max_size = max(max_size, sz[b]);
    parent[a]=parent[b];
}

void dfs(int current, bool new_set, int neighbor){
    if(W[current-1]%2!=0){
        new_set=true;
    }else{
        if (new_set){
            make_set(current);
            neighbor=current;
            new_set=false;
        }else{
            union_set(current,neighbor);
        }
    }
    for(auto e: adj[current]){
        dfs(e,new_set,neighbor);
    }
}

int main(){
    init(N);
    adj[1].pb(2);
    adj[1].pb(3);
    adj[2].pb(4);
    adj[2].pb(5);
    adj[4].pb(6);
    adj[6].pb(7);
    dfs(1,true,1);
    cout << max_size << '\n';
    return 0;
}