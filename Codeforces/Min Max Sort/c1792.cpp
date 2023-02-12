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
        int n;
        cin >> n;
        int m[n+1];
        fr(0,n,i){
            int nm;
            cin >> nm;
            m[nm]=i+1;
        }
        int lp=1;
        int rp=2;
        int ans=n/2;
        int mins=0;
        int maxs=0;
        int pp=1;
        while(rp<=n){
            //cout << "\ntesting rp: "<<m[rp]<<" with lp: "<<m[lp];
            if(m[rp]>m[pp]){
                mins=lp-1;
                maxs=n-rp;
                int lowest = min(mins,maxs);
                int l_ans = lowest;
                mins-=lowest;
                maxs-=lowest;
                l_ans+=max(mins,maxs);
                ans = min(ans,l_ans);
                //cout << "\nlocal ans: "<<l_ans;
                //cout << "\nans: "<<ans;
                pp = rp;
                rp++;
            }else{
                lp=rp;
                pp=lp;
                rp++;
            }
        }
        cout << ans <<'\n';
    }
}