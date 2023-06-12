#include <bits/stdc++.h>
#define pb push_back
#define vi vector<int>
#define ll long long
#define vll vector<long long>
#define pll pair<ll,ll>
using namespace std;
typedef std::tuple<int,int,int> mytuple;

int main(){
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        map<ll,vector<ll>> s;
        while (n--){
            ll a,b;
            cin >> a >> b;
            s[a].push_back(b);
        }
        ll ans=0;
        for(auto p: s){
            std::sort(p.second.begin(), p.second.end());
            std::reverse(p.second.begin(), p.second.end());
            for (int i = 0; i < p.second.size(); ++i) {
                if (i+1>p.first) break;
                ans+=p.second[i];
            }
        }
        cout << ans <<'\n';
    }
}