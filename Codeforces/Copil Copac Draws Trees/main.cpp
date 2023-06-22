#include <bits/stdc++.h>
#define pb push_back
#define vi vector<int>
#define ll long long
#define vll vector<long long>
#define pll pair<ll,ll>
using namespace std;
typedef std::tuple<int,int,int> mytuple;

const int N = ( 2 * 10e5 )+ 1;
vector<pair<int,int>> adj[N];
bool visited[N];
int ans;

void dfs(int v, int my, int last ,int sum){
    if (visited[v]) return;
    int extra = 0;
    if (my<last){
        extra++;
    }
    ans = max(ans,sum + extra);
    visited[v]=true;
    for(auto p: adj[v]){
        if (visited[p.first]) continue;
        //cout << "comparing pair ("<<v<<","<<p.first<<")\n";
        dfs(p.first,p.second,my,sum+extra);
    }
    return;
}

int main(){
    for (int i = 0; i < N; ++i) {
        visited[i]= false;
    }
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        ans=0;
        for (int i = 0; i <= n; ++i) {
            adj[i].clear();
            visited[i]= false;
        }
        for (int i = 0; i < n-1; ++i) {
            int a,b;
            cin >> a >> b;
            adj[a].emplace_back(b,i);
            adj[b].push_back({a,i});
        }
        dfs(1,-1,n+1,0);
        cout << ans <<'\n';
    }
}
