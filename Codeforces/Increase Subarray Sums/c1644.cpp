#include <bits/stdc++.h>
#define pb push_back
#define vi vector<int>
#define ff(size) for (int i = 0; i < size; i++)
#define viin(vec,n) ff(n){int x; cin>>x; vec.pb(x);}
#define ll long long
#define vll vector<ll>
#define vllin(vec,n) ff(n){ll x; cin>>x; vec.pb(x);}
#define fr(size, i) for (int i=0; i<size; i++)
#define fmap(map,puntero) for (auto puntero=map.begin(); puntero!=map.end(); puntero++)
#define vec_reversrt(vec) sort(vec.begin(), vec.end(), greater<>())
#define frs(siz, init, j) for (int j=init; j<siz; j++)
#define len(arr) arr.size()
using namespace std;

void sol(int n, int x, vll a){
    ll ans[n+1];
    ll mxs[n+1];
    fill_n(mxs,n+1,INT_MIN);
    mxs[0]=0;
    fr(n,l){
        ll sum = 0;
        frs(n,l,r){
            sum+=a[r];
            mxs[r-l+1]=max(mxs[r-l+1],sum);
        }
    }
    ll max_sum = LONG_LONG_MIN;
    int max_sum_length;
    fr(n+1,j){
        if (mxs[j]>max_sum){
            max_sum = mxs[j];
            max_sum_length = j;
        }
    }
    fr(n+1,k){
        if (k<=max_sum_length){
            ans[k]=max_sum+k*x;
        }else{
            ll now_max_sum = 0;
            fr(n+1,i){
                now_max_sum = max( now_max_sum, mxs[i]+min(k,i) * x );
            }
            ans[k]=now_max_sum;
        }
    }
    fr(n+1,i){
        cout << ans[i] << " ";
    }
    cout << endl;
}


int main(){
    int t;
    cin >> t;
    while(t--){
        int n,x;
        cin >> n >> x;
        vll a;
        vllin(a,n);
        sol(n,x,a);
    }
    return  0;
}