#include <bits/stdc++.h>
#define ll long long
using namespace std;

const ll L=1;
const ll R = 1e13 +1;

int main(){
    int n,m;
    cin >> n >> m;
    map<int,vector<pair<int,int>>> f;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            int c;
            cin >> c;
            f[c].emplace_back(i,j);
        }
    }
    ll ans=0;
    for(auto c: f){
        map<int,int> row;
        map<int,int> col;
        for (int i = 0; i < c.second.size(); ++i) {
            row[c.second[i].first]++;
            col[c.second[i].second]++;
        }
        int i;
        bool start=true;
        ll ac=0;
        ll nms=0;
        for(auto p: row){
            if (start){
                start=false;
            }else{
                ac = ac + nms*(p.first-i);
                ans+=(ac*p.second);
            }
            i = p.first;
            nms+=p.second;
        }
        start=true;
        ac=0;
        nms=0;
        for(auto p: col){
            if (start){
                start=false;
            }else{
                ac = ac + nms*(p.first-i);
                ans+=(ac*p.second);
            }
            i = p.first;
            nms+=p.second;
        }
    }
    cout << ans <<'\n';
}