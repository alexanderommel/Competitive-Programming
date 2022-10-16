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

bool test(int steps,vi H){

}

void sol(vll a,vll k){
    vll H;
    vll AH;
    H.pb(a[0]);
    AH.pb(a[0]);
    fr(1,a.size(),i){
        H.pb(max(H[i-1],a[i]));
        ll sum = a[i] + AH[i-1];
        AH.pb(sum);
    }
    fr(0,k.size(),i){
        if (k[i]==0){
            cout << 0 << " ";
            continue;
        }
        ll L=0;
        ll R=a.size()-1;
        ll ans=-1;
        while(L<=R){
            ll X = (L+R)/2;
            if (k[i]>=H[X]){
                L=X+1;
                ans = max(ans,X);
            }else{
                R=X-1;
            }

        }
        if (ans==-1){
            cout << 0 << " ";
            continue;
        }
        cout << AH[ans] << " ";
    }
    cout << '\n';
}

int main(){
    int t;
    cin >> t;
    while(t--){
        ll n,q;
        cin >> n >> q;
        vll a,k;
        vllin(a,n);
        vllin(k,q);
        sol(a,k);
    }
    return 0;
}