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

    int n,q;
    cin >> n >> q;
    ll v[n][2];
    ll sum = 0;
    fr(0,n,i){
        ll ai;
        cin >> ai;
        sum+=ai;
        v[i][0]=ai;
        v[i][1]=0;
    }
    ll current_round=0;
    ll all_value=-1;
    fr(0,q,j){
        int t;
        cin >> t;
        if (t==1){
            ll i,x;
            cin >> i  >> x;
            i--;
            if (v[i][1]<current_round){
                v[i][0]=all_value;
                v[i][1]=current_round;
            }

            sum = sum - v[i][0] + x;
            v[i][0] = x;

            cout << sum << '\n';
        }else{
            ll x;
            cin >> x;
            current_round++;
            sum = n * x;
            all_value = x;
            cout << sum << '\n';
        }
    }

    return 0;
}
