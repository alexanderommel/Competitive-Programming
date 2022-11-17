#include <bits/stdc++.h>
#define pb push_back
#define vi vector<int>
#define ll long long
#define vll vector<long long>
#define fr(s,n,i) for (long long i=s; i<n; ++i)
#define fri(s,e,i) for (long long i=s; i>=e; --i)
#define len(arr) arr.size()
#define viin(vec,n) fr(0,n,i){int x; cin>>x; vec.pb(x);}
#define vllin(vec,n) fr(0,n,i){ll x; cin>>x; vec.pb(x);}
using namespace std;

int main() {
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);


    int t;
    cin >> t;
    while(t--){
        string s;
        cin >> s;
        int n = s.length();

        int z=0;
        int o=0;

        vector<pair<int,int>> f;

        fr(0,n,i){
            if(s[i]=='0'){
                z++;
            }else{
                o++;
            }
            f.pb({z,o});
        }

        int ans=INT_MAX;

        fr(0,n,i){
            int a,b;
            a = f[i].first + o - f[i].second;
            b = f[i].second + z - f[i].first;
            ans = min(ans,min(a,b));
        }

        cout << ans << '\n';

    }
    return 0;
}