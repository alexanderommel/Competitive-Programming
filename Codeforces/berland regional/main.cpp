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
        ll m[2][n];
        int i=0;
        while(i<n){
            cin >> m[0][i];
            i++;
        }
        i=0;
        while(i<n){
            cin >> m[1][i];
            i++;
        }
        map<ll,vector<ll>> mp;
        i=0;
        while(i<n){
            mp[m[0][i]].push_back(m[1][i]);
            i++;
        }
        ll ans[n+1];
        for(int i=0;i<=n;i++){
            ans[i]=0;
        }
        for(auto par: mp) {
            std::sort(par.second.begin(), par.second.end());
            std::reverse(par.second.begin(), par.second.end());
            ll S[par.second.size()+1];
            S[0]=0;
            for(int i=1;i<=par.second.size();i++){
                S[i]=S[i-1]+par.second[i-1];
            }
            int k=1;
            while(k<=n && k<=par.second.size()){
                int rem = par.second.size()%k;
                ans[k]+=S[par.second.size()-rem];
                k++;
            }
        }
        for(int i=1;i<=n;i++){
            cout << ans[i]<<" ";
        }
        cout << '\n';
    }
}
