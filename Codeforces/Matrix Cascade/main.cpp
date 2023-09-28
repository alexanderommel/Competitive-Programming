#include <bits/stdc++.h>
#define ll long long
using namespace std;

char inv(char a){
    if(a=='0') return '1';
    return '0';
}

int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        int ans=0;
        vector<pair<int,int>> a(n+1,{0,0});
        vector<int> mask(n+1,0);
        for (int i = 0; i < n; ++i) {
            string s,h;
            cin >> s;
            h = s;
            vector<int> rep;
            for (int j = 0; j < n; ++j) {
                if (mask[j+1]==1) h[j]=inv(s[j]);
                if (h[j]=='1'){
                    rep.push_back(j);
                    ans++;
                }
            }
            //cout << "original: "<<s<<'\n';
            //cout << "after: "<<h<<'\n';
            for(auto p: rep) mask[p+1]=1-mask[p+1];
            vector<pair<int,int>> b(n+1,{0,0});
            for (int j = 1; j <= n; ++j) {
                if(a[j].first==1 && j>1) b[j-1].first = 1 - b[j-1].first;
                if(a[j].second==1 && j<n) b[j+1].second = 1 - b[j+1].second;
            }
            for(auto p: rep){
                if(p>0) b[p].first = 1 - b[p].first;
                if(p+2<=n) b[p+2].second = 1 - b[p+2].second;
            }
            a = b;
            for (int j = 1; j <= n; ++j) {
                if (a[j].first==1) mask[j]=1-mask[j];
                if (a[j].second==1) mask[j]=1-mask[j];
            }
        }
        cout << ans <<'\n';
    }
}