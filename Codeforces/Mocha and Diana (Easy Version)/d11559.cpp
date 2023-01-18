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

const int N=1001;
int ANS=0;
vector<pair<int,int>> LOG;
vector<int> parent, sz;
vector<int> parent2, sz2;

void init(){
    parent = vector<int>(N,0);
    sz = vector<int>(N,0);
    for(int i=1;i <N; i++){
        parent[i]=i;
        sz[i]=1;
    }

    parent2 = vector<int>(N,0);
    sz2 = vector<int>(N,0);
    for(int i=1;i <N; i++){
        parent2[i]=i;
        sz2[i]=1;
    }
}

int find_representative(int e){
    while(e!=parent[e]){parent[e]=parent[parent[e]]; e = parent[e];}return e;
}
void union_set(int u,int v){
    int a = find_representative(u); int b = find_representative(v);
    if(a==b){ return; }
    ANS++;
    if(sz[a]>sz[b]){swap(a,b);}
    sz[b]+=sz[a];
    sz[a]=0;
    parent[a]=parent[b];
}

int find_representative2(int e){
    while(e!=parent2[e]){parent2[e]=parent2[parent2[e]]; e = parent2[e];}return e;
}
void union_set2(int u,int v){
    int a = find_representative2(u); int b = find_representative2(v);
    if(a==b){ return; }
    if(sz2[a]>sz2[b]){swap(a,b);}
    sz2[b]+=sz2[a];
    sz2[a]=0;
    parent2[a]=parent2[b];
}

int main(){
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    init();

    int n,m1,m2;
    cin >> n >> m1 >> m2;
    fr(0,m1,i){
        int a,b;
        cin >> a >> b;
        union_set(a,b);
    }
    fr(0,m2,i){
        int a,b;
        cin >> a >> b;
        union_set2(a,b);
    }

    ANS=0;

    fr(1,n+1,i){
        fr(1,n+1,j){
            if(i==j){
                continue;
            }
            int ra1 = find_representative(i);
            int rb1 = find_representative(j);
            if (ra1!=rb1){
                int ra2 = find_representative2(i);
                int rb2 = find_representative2(j);
                if (ra2!=rb2){
                    LOG.pb({i,j});
                    union_set(i,j);
                    union_set2(i,j);
                }
            }
        }
    }

    cout << ANS << '\n';
    fr(0,LOG.size(),k){
        cout << LOG[k].first << " " << LOG[k].second << '\n';
    }
    return 0;
}
