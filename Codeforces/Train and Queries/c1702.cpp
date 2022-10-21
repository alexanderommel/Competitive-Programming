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

int main(){
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    int t;
    cin >> t;
    while(t--){
        int n,k;
        cin >> n >> k;
        vll u;
        vllin(u,n);
        map<ll,pair<ll,ll>> queues;
        fr(0,n,i){
            int fff=0;
            int sss=0;
            if(queues.count(u[i])<1){
                fff = i;
                sss = i;
                queues[u[i]]={fff,sss};
            }else{
                fff = queues[u[i]].first;
                sss = i;
                queues[u[i]]={fff,sss};
            }
        }

        fr(0,k,i){
            ll a,b;
            cin >> a >> b;
            if (queues.count(a)>0 && queues.count(b)>0){
                if (queues[b].second>=queues[a].first){
                    cout << "YES" << '\n';
                }else{
                    cout << "NO" << '\n';
                }
            }else{
                cout << "NO" << '\n';
            }
        }
    }
}