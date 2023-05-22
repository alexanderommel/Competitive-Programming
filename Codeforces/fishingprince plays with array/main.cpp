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
        ll n,m;
        cin >> n >> m;
        int l=0;
        vector<pair<ll,ll>> a;
        vector<pair<ll,ll>> b;

        for(int i=0;i<n;i++) {
            ll nm;
            cin >> nm;
            ll rep=1;
            while(nm%m==0){
                rep*=m;
                nm=nm/m;
            }
            if(i>0){
                if(nm==a[l].first){
                    a[l].second+=rep;
                }else{
                    l++;
                    a.push_back({nm,rep});
                }
            }else{
                a.push_back({nm,rep});
            }
        }

        ll k;
        cin >> k;
        l=0;

        for(int i=0;i<k;i++) {
            ll nm;
            cin >> nm;
            ll rep=1;
            while(nm%m==0){
                rep*=m;
                nm=nm/m;
            }
            if(i>0){
                if(nm==b[l].first){
                    b[l].second+=rep;
                }else{
                    l++;
                    b.push_back({nm,rep});
                }
            }else{
                b.push_back({nm,rep});
            }
        }

        if (a.size()!=b.size()){
            cout <<"NO\n";
        }else{
            bool ans=true;
            for(int i=0;i<a.size();i++) {
                if(a[i].first!=b[i].first || a[i].second!=b[i].second){
                    ans = false;
                    break;
                }
            }
            if(ans){
                cout <<"YES\n";
            }else{
                cout <<"NO\n";
            }
        }

    }
}