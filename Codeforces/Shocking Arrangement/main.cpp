#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main(){
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        int zrs=0;
        vector<ll> pp;
        vector<ll> nn;
        for (int i = 0; i < n; ++i) {
            ll nm;
            cin >> nm;
            if (nm>=0){
                pp.push_back(nm);
            }else{
                nn.push_back(nm);
            }
            if (nm==0) zrs++;
        }
        if (zrs==n){
            cout <<"No\n";
            continue;
        }
        std::sort(pp.begin(), pp.end());
        std::sort(nn.begin(), nn.end());
        cout << "Yes\n";
        vector<ll> ans;
        int pos=0;
        int neg=0;
        ll sum=0;
        for (int i = 0; i < n; ++i) {
            if (neg==nn.size()){
                ans.push_back(pp[pos]);
                pos++;
                continue;
            }
            if (pos==pp.size()){
                ans.push_back(nn[neg]);
                neg++;
                continue;
            }
            if (sum>=0){
                ans.push_back(nn[neg]);
                sum+=nn[neg];
                neg++;
            }else{
                ans.push_back(pp[pos]);
                sum+=pp[pos];
                pos++;
            }
        }
        for (int i = 0; i < n; ++i) {
            cout << ans[i]<<" ";
        }
        cout <<'\n';
    }
}