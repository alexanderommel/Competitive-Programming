#include <bits/stdc++.h>
#define ll long long
using namespace std;

const int N = 2 + 4*(1e5);
vector<ll> adj[N];
ll parents[N];


int main(){
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        map<int,int> a;
        for (int i = 0; i < n; ++i) {
            int nm;cin >> nm;
            a[nm]++;
        }
        int h=-1;
        int q=INT_MAX;
        bool ans=true;
        for(auto p: a){
            if (p.first!=h+1){
                ans=false;
                break;
            }
            if(p.second>q){
                ans=false;
                break;
            }
            h=p.first;
            q=p.second;
        }
        if (ans)    {
            cout << "YES\n";
        }else{
            cout << "NO\n";
        }
    }
}
