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

typedef std::pair<ll,ll> mypair;
bool my_comparator ( const mypair& l, const mypair& r){
    return l.first > r.first;
}

int main(){
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        vi a,b;
        viin(a,n);
        viin(b,n);

        ll current;

        ll ans = abs((a[0]-b[0])) + abs((a[n-1]-b[n-1]));
        current = abs((a[0]-b[n-1])) + abs((a[n-1]-b[0]));
        ans = min(ans,current);

        ll three = abs(a[0]-b[0]);
        ll temp1=LONG_LONG_MAX,temp2=LONG_LONG_MAX;
        fr(0,n-1,i){
            ll cc = abs(a[n-1]-b[i]);
            ll dd = abs(a[i]-b[n-1]);
            temp1 = min(temp1,cc);
            temp2 = min(temp2,dd);
        }
        three+=(temp1+temp2);
        ans = min(ans,three);

        three = abs(a[n-1]-b[n-1]);
        temp1=LONG_LONG_MAX;
        temp2=LONG_LONG_MAX;
        fr(1,n,i){
            ll cc = abs(a[0]-b[i]);
            ll dd = abs(a[i]-b[0]);
            temp1 = min(temp1,cc);
            temp2 = min(temp2,dd);
        }
        three+=(temp1+temp2);
        ans = min(ans,three);

        three = abs(a[0]-b[n-1]);
        temp1=LONG_LONG_MAX;
        temp2=LONG_LONG_MAX;
        ll temp3=LONG_LONG_MAX;
        ll temp4=LONG_LONG_MAX;
        fr(0,n,i){
            ll cc = abs(a[n-1]-b[i]);
            ll dd = abs(a[i]-b[0]);
            ll ee = abs(a[0]-b[i]);
            ll ff = abs(a[i]-b[n-1]);
            temp1 = min(temp1,cc);
            temp2 = min(temp2,dd);
            temp3 = min(temp3,ee);
            temp4 = min(temp4,ff);
        }
        ll a111= temp1 + temp2 + abs(a[0]-b[n-1]);
        ll a222 = temp3 + temp4 + abs(a[n-1]-b[0]);
        ans = min(ans,a111);
        ans = min(ans,a222);

        temp1=LONG_LONG_MAX;
        temp2=LONG_LONG_MAX;
        temp3=LONG_LONG_MAX;
        temp4=LONG_LONG_MAX;
        fr(1,n-1,i){
            ll cc = abs(a[n-1]-b[i]);
            ll dd = abs(a[i]-b[0]);
            ll ee = abs(a[0]-b[i]);
            ll ff = abs(a[i]-b[n-1]);
            temp1 = min(temp1,cc);
            temp2 = min(temp2,dd);
            temp3 = min(temp3,ee);
            temp4 = min(temp4,ff);
        }
        ll res = temp1+temp2+temp3+temp4;
        ans = min(ans,res);

        cout << ans << '\n';

    }

    return 0;
}
