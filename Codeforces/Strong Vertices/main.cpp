#include <bits/stdc++.h>
#define ll long long
using namespace std;

const int th = 40001;

int main(){
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        ll a[n];
        ll b[n];
        bool c[n];
        for (int i = 0; i < n; ++i) {
            c[i]=true;
        }
        for (int i = 0; i < n; ++i) {
            cin >> a[i];
        }
        for (int i = 0; i < n; ++i) {
            cin >> b[i];
        }
        int p=0;
        vector<int> adj[n];
        while(p<n){
            int i =  p+1;
            for (; i < n; ++i) {
                ll ka = a[p]-a[i];
                ll kb = b[p]-b[i];
                if (ka>kb){
                    c[i]=false;
                }
                if(ka==kb){
                    adj[p].push_back(i);
                }
                if (ka<kb){
                    c[p]=false;
                    break;
                }
            }
            p = i;
        }
        for (int i = 0; i < n; ++i) {
            if (!c[i]){
                for (int j = 0; j < adj[i].size(); ++j) {
                    c[adj[i][j]]=false;
                }
            }
        }

        vector<int> ans;
        for (int i = 0; i < n; ++i) {
            if (c[i]) ans.push_back(i+1);
        }
        std::sort(ans.begin(), ans.end());
        cout << ans.size()<<'\n';
        for (int i = 0; i < ans.size(); ++i) {
            cout << ans[i] << " ";
        }
        cout <<'\n';
    }
}