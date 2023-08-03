#include <bits/stdc++.h>
#define ll long long
using namespace std;

const int NNN= 101;

vector<int> adj[NNN];
bool mem[NNN];


void dfs(int node, int i){
    if (mem[node]) return;
    mem[node]=true;
    for(auto s: adj[node]){
        dfs(s,i);
    }
}

int main(){
    int t;
    cin >> t;
    while(t--){
        string a,b,c;
        cin >> a >> b >> c;
        if((a[0]==a[1] && a[1]==a[2]) || (a[0]==b[1] && b[1]==c[2]) || (a[0]==b[0] && b[0]==c[0])){
            if(a[0]!='.'){
                cout << a[0]<<'\n';
                continue;
            }
        }
        if((c[0]==c[1] && c[1]==c[2]) || (a[0]==b[1] && b[1]==c[2]) || (a[2]==b[2] && b[2]==c[2])){
            if(c[2]!='.'){
                cout << c[2]<<'\n';
                continue;
            }
        }
        if(a[2]==b[1] && b[1]==c[0]){
            if(c[0]!='.'){
                cout << c[0]<<'\n';
                continue;
            }
        }
        if((b[0]==b[1] && b[1]==b[2]) || (a[1]==b[1] && b[1]==c[1])){
            if(b[1]!='.'){
                cout << b[1]<<'\n';
                continue;
            }
        }
        cout << "DRAW\n";
    }
}