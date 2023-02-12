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
#define LSB(i)  ((i) & -(i))

using namespace std;
typedef map<ll,ll, greater<ll>> desc_map;
typedef std::pair<ll,ll> mypair;
typedef std::priority_queue<ll> maxqueue;
typedef std::priority_queue <ll, vector<ll>, greater<ll>> minqueue;


int main(){
    int t;
    cin >> t;
    while(t--){
        int n,s;
        cin >> n >> s;
        vector<pair<ll,ll>> a;
        ll first;
        cin >> first;
        a.pb({first,first});
        fr(1,n-1,i){
            ll nm;cin >> nm;
            if(s>=nm){
                a.pb({0,nm});
            }else{
                a.pb({s,nm-s});
            }
        }
        ll last;
        cin >> last;
        a.pb({last,last});
        ll dp[n][2];
        dp[0][0]=0; dp[0][1]=0;
        //fr(0,a.size(),z){
          //  //cout <<"\npair: "<<a[z].first<<" "<<a[z].second;
        //}
        //cout <<'\n';
        fr(1,n,i){
            fr(0,2,j){
                if(j==0){
                    dp[i][0]=min(dp[i-1][0]+a[i-1].first*a[i].second,dp[i-1][1]+a[i-1].second*a[i].second);
                }else{
                    dp[i][1]=min(dp[i-1][0]+a[i-1].first*a[i].first,dp[i-1][1]+a[i-1].second*a[i].first);
                }
            }
        }
        cout << min(dp[n-1][0],dp[n-1][0]) <<'\n';
    }
}