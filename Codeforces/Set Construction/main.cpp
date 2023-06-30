#include <bits/stdc++.h>
#define ll long long
using namespace std;

const int NNN= 101;

vector<int> adj[NNN];
vector<map<int,int>> ans(NNN);
bool mem[NNN];

void dfs(int node, int i){
    if (mem[node]) return;
    mem[node]=true;
    for(auto s: adj[node]){
        ans[s][i]++;
        dfs(s,i);
    }
}

int main(){
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        for (int i = 0; i <= n; ++i) {
            adj[i].clear();
            ans[i].clear();
        }
        for (int i = 1; i <=n ; ++i) {
            ans[i][i]++;
        }
        for (int i = 0; i < n; ++i) {
            string s;
            cin >> s;
            for (int j = 0; j < n; ++j) {
                int nm = s[j]-'0';
                if (nm==1){
                    adj[i+1].push_back(j+1) ;
                }
            }
        }
        for (int i = 1; i <= n; ++i) {
            for (int j = 0; j <=n ; ++j) {
                mem[j]=false;
            }
            dfs(i,i);
        }
        for (int i = 1; i <=n ; ++i) {
            int q=0;
            vector<int> pr;
            for(auto p: ans[i]){
                if (p.second>0){
                    q++;
                    pr.push_back(p.first);
                }
            }
            cout << q <<" ";
            for(auto nm: pr){
                cout << nm <<" ";
            }
            cout <<'\n';
        }

    }
}