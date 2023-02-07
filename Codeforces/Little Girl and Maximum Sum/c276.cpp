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

void update(ll *BIT,ll index, ll value, int n){
    ll k = index;
    while(k<=n){
        BIT[k]+=value;
        k += k&-k;
    }
}


ll sum(ll *BIT, ll index){
    if (index<=0){
        return 0;
    }
    ll k = index;
    ll ans = 0;
    while(k>0){
        ans+=BIT[k];
        k -= k&-k;
    }
    return ans;
}

ll *buildBIT(int n){
    ll *BIT = new long long[n+1];
    fr(1,n+1,i){
        BIT[i]=0;
    }
    return BIT;
}

typedef std::pair<ll,ll> mypair;
bool my_comparator ( const mypair& l, const mypair& r){
    return l.first > r.first;
}

int main(){
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    int n,q;
    cin >> n >> q;
    vi a;
    viin(a,n);
    ll *BIT= buildBIT(n);

    vector<pair<ll,ll>> queries;

    fr(0,q,i){
        ll l,r;
        cin >> l >> r;
        queries.pb({l,r});
        update(BIT,l,1,n);
        if (r+1>n){
            continue;
        }
        update(BIT,r+1,-1,n);
    }

    vector<pair<ll, ll>> c;

    fr(1,n+1,i){
        ll suma = sum(BIT,i) - 0;
        c.pb({suma,i-1});
    }

    std::sort(c.begin(), c.end(), my_comparator);
    std::sort(a.begin(), a.end());
    std::reverse(a.begin(), a.end());

    ll reordered[n];

    fr(0,n,i){
        reordered[c[i].second]=a[i];
    }

    ll ans=0;
    ll *BIT_FINAL= buildBIT(n);
    fr(0,n,j){
        update(BIT_FINAL,j+1,reordered[j],n);
    }

    fr(0,q,i){
        ll suma = sum(BIT_FINAL,queries[i].second) - sum(BIT_FINAL,queries[i].first-1);
        ans+=suma;
    }

    cout << ans << '\n';

    return 0;
}
