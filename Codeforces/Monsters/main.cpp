#include <bits/stdc++.h>
#define ll long long
using namespace std;

const int N = 3 + (1e6);
const int Ke= 2+ (1e6);
ll prepp[N];
const int LM=36;

bool comparator2(pair<ll,ll> a, pair<ll,ll> b){
    bool as = false;
    if (a.first < b.first){
        return as;
    }
    else if(a.first > b.first){
        as = true;
        return as;
    }
    as = false;
    return a.second < b.second;

}

int main(){
    int t;
    cin >> t;
    while(t--){
        int n,k;
        cin >> n >> k;
        vector<ll> res;
        vector<pair<ll,ll>> ans(n);
        int a[n];
        for (int i = 0; i < n; ++i) {
            cin >> a[i];
            a[i] %=k;
        }
        for (int i = 0; i < n; ++i) {

        }
        for (int i = 0; i < n; ++i) {
            if (a[i]==0){
                res.push_back(i+1);
            }
        }
        for (int i = 0; i < n; ++i) {
            ans[i].first=a[i];
            ans[i].second=  i + 1;
        }
        sort(ans.begin(), ans.end(), comparator2);
        for(auto pp: ans){
            if (pp.first==0){
                k += 1;
            }else{
                res.push_back(pp.second);
            }
        }
        for (int i = 0; i < res.size(); ++i) {
            cout << res[i] <<" ";
        }
        cout <<'\n';
    }
}