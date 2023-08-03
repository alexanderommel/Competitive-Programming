#include <bits/stdc++.h>
#define ll long long
using namespace std;

const int N = 3 + (1e6);
const int Ke= 2+ (1e6);
ll prepp[N];
const int LM=36;

int main(){
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        vector<pair<ll,int>> a;
        vector<pair<ll,int>> b;
        vector<int> ia;
        vector<int> ib;
        for (int i = 0; i < n; ++i) {
            ll nm;
            cin >> nm;
            if (nm%2==0){
                a.emplace_back(nm,i);
                ia.push_back(i);

            }else{
                b.emplace_back(nm,i);
                ib.push_back(i);
            }
        }
        std::sort(a.begin(), a.end());
        std::sort(b.begin(), b.end());
        ll ans[n];
        for (int i = 0; i < a.size(); ++i) {
            ans[ia[i]]=a[i].first;
        }
        for (int i = 0; i < b.size(); ++i) {
            ans[ib[i]]=b[i].first;
        }
        bool aans=true;
        for (int i = 0; i < n-1; ++i) {
            if (ans[i]>ans[i+1]){
                aans=false;
                break;
            }
        }
        if (aans){
            cout << "YES\n";
        }else{
            cout << "NO\n";
        }
    }
}