#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin>>t;
    while(t--){
        int n;
        cin >> n;
        vector<pair<ll,ll>> v;
        vector<pair<ll,ll>> ans;
        for (int i = 0; i < n; ++i) {
            ll a,b,c,d;
            cin >> a >> b >> c >> d;
            v.emplace_back(a,d);
        }
        std::sort(v.begin(), v.end());
        v.emplace_back(LONG_LONG_MAX,LONG_LONG_MAX);
        int i=0;
        ll a = v[i].first;
        ll b = v[i].second;
        i++;
        while(i<n+1){
            if (b>=v[i].first){
                b = max(b,v[i].second);
            }else{
                ans.emplace_back(a,b);
                ans.emplace_back(b,-1);
                a = v[i].first;
                b = v[i].second;
            }
            i++;
        }
        int sz = ans.size();
        int q;
        cin >> q;
        for (int j = 0; j < q; ++j) {
            ll nm;
            cin >> nm;
            int l=0;
            int r=sz-1;
            ll res = nm;
            ll loc = 0;
            int x;
            while(l<=r && nm>=ans[0].first && nm<=ans[sz-1].first ){
                x = (l+r)/2;
                if (nm>=ans[x].first){
                    loc = ans[x].second;
                    l = x+1;
                }else{
                    r = x-1;
                }
            }
            cout << max(res,loc) << " ";
        }
        cout << '\n';
    }
    return 0;
}