#include <bits/stdc++.h>
#define pb push_back
#define vi vector<int>
#define pii pair<int,int>
#define ll long long
#define vll vector<long long>
#define fr(s,n,i) for (long long i=s; i<n; ++i)
#define fri(s,e,i) for (long long i=s; i>=e; --i)
#define len(arr) arr.size()
#define viin(vec,n) fr(0,n,i){int x; cin>>x; vec.pb(x);}
#define vllin(vec,n) fr(0,n,i){ll x; cin>>x; vec.pb(x);}
using namespace std;

const int MAX_N = 4005;
vector<int> tree[MAX_N];
char colors[MAX_N];
int ans=0;

pii dp(int v){
    char c = colors[v];
    int whites=0;
    int blacks=0;
    pii vals;
    if (c=='W'){
        vals = {1,0};
        whites++;
    }else{
        vals = {0,1};
        blacks++;
    }
    if (tree[v].empty()){
        return vals;
    }
    for(int child_vertex: tree[v]){
        pii values = dp(child_vertex);
        whites+=values.first;
        blacks+=values.second;
    }
    if (whites==blacks){
        ans++;
    }
    return {whites,blacks};
}

int main(){
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        fr(2,n+1,i){
            int parent;
            cin >> parent;
            tree[parent].pb(i);
        }
        string cls;
        cin >> cls;
        fr(1,n+1,i){
            colors[i]=cls[i-1];
        }
        ans=0;
        dp(1);
        cout << ans << '\n';
        fr(1,n+1,i){
            tree[i].clear();
        }
    }
}