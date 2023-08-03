#include <bits/stdc++.h>
#define ll long long
using namespace std;

const int NNN= 101;

vector<int> adj[NNN];
bool mem[NNN];

int main(){
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        // ll res=0;
        ll ans = 0;
        for (int i = 0; i < n; ++i) {
            int ai,bi;
            cin >> ai >> bi;
            if(bi<ai){
                ans++;
            }else{

            }
        }
        cout << ans <<'\n';
    }
}