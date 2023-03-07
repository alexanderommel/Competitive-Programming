#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define fr(s,n,i) for (long long i=s; i<n; ++i)


int main(){

    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        vector<pair<ll,ll>> a;
        vector<pair<ll,ll>> b;
        int c[n];
        for(int i=0;i<n;i++)    {
            ll nm;
            cin >> nm;
            if(nm<0){
                a.push_back({nm,i});
            }else{
                b.push_back({nm,i}) ;
            }
            c[i]=nm;
        }
        std::sort(a.begin(), a.end());
        std::sort(b.begin(), b.end());
        int i=0;
        for(;i+1<a.size();i+=2){
            c[a[i].second]*=-1;
            c[a[i+1].second]*=-1;
        }
        if(i==a.size()-1 && b.size()>0){
            if(a[i].first*-1>b[0].first){
                c[a[i].second]*=-1;
                c[b[0].second]*=-1;
            }
        }
        ll ans=0;
        for(int i=0;i<n;i++)    {
            ans+=c[i];
        }
        cout << ans <<'\n';
    }
}