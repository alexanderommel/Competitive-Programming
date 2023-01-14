#include <bits/stdc++.h>
using namespace std;

struct DSU{
    int num_sets; int max_size;
    vector<int> parent, size;
    void init(int n){
        parent = vector<int>(n+1,0);
        size = vector<int>(n+1,0);
        for(int i=1;i <=n; i++){parent[i]=i, size[i]=1;}
        num_sets = n; max_size=1;
    }
    void make_set(int e){parent[e]=e;}
    int find_representative(int e){
        while(e!=parent[e]){parent[e]=parent[parent[e]]; e = parent[e];}return e;
    }
    void union_set(int u,int v){
        int a = find_representative(u); int b = find_representative(v);
        if(a==b){ return; }
        num_sets--;
        if(size[a]>size[b]){swap(a,b);}
        size[b]+=size[a]; size[a]=0; max_size = max(max_size, size[b]); parent[a]=parent[b];
    }
};