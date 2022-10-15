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

void sol(int n, int k, vi a){
    vi R;
    fr(1,n,i){
        if (2*a[i]<=a[i-1]){
            R.pb(i);
        }
    }
    std::reverse(R.begin(), R.end());
    int ans=0;
    fr(0,n-k,i){
        if (R.size()>0){
            if (i==R[R.size()-1]){
                R.pop_back();
            }
        }
        if (R.size()>0){
            if(i+k>=R[R.size()-1]){
                continue;
            }
        }
        ans++;
    }
    cout << ans << '\n';
}

int main(){
    int t;
    cin >> t;
    while(t--){
        int n,k;
        cin >> n >> k;
        vi a;
        viin(a,n);
        sol(n,k,a);
    }
}