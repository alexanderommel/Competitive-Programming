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

//using u64 = uint64_t;
//using u128 = __uint128_t;

ll binpower(ll base, ll e, ll mod) {
    ll result = 1;
    base %= mod;
    while (e) {
        if (e & 1)
            result = (ll)result * base % mod;
        base = (ll)base * base % mod;
        e >>= 1;
    }
    return result;
}

bool check_composite(ll n, ll a, ll d, int s) {
    ll x = binpower(a, d, n);
    if (x == 1 || x == n - 1)
        return false;
    for (int r = 1; r < s; r++) {
        x = (ll)x * x % n;
        if (x == n - 1)
            return false;
    }
    return true;
};

bool MillerRabin(ll n, int iter=5) { // returns true if n is probably prime, else returns false.
    if (n < 4)
        return n == 2 || n == 3;

    int s = 0;
    ll d = n - 1;
    while ((d & 1) == 0) {
        d >>= 1;
        s++;
    }

    for (ll i = 0; i < iter; i++) {
        int a = 2 + rand() % (n - 3);
        if (check_composite(n, a, d, s))
            return false;
    }
    return true;
}

map<ll,ll> factores_primos;
bool ok=false;

void trial_division3(long long n) {
    map<ll,ll> f;
    for (int d : {2, 3, 5}) {
        while (n % d == 0) {
            if(f.count(d)<1){
                f[d]++;
                factores_primos[d]++;
                if(factores_primos[d]>1){
                    ok=true;
                }
            }
            n /= d;
        }
    }
    static array<int, 8> increments = {4, 2, 4, 2, 4, 6, 2, 6};
    int i = 0;
    for (long long d = 7; d * d <= n; d += increments[i++]) {
        if(ok){
            break;
        }
        while (n % d == 0 && !ok) {
            if(f.count(d)<1){
                f[d]++;
                factores_primos[d]++;
                if(factores_primos[d]>1){
                    ok=true;
                }
            }
            n /= d;
        }
        if (i == 8)
            i = 0;
    }
    if (n > 1){
        f[n]++;
        factores_primos[n]++;
        if(factores_primos[n]>1){
            ok=true;
        }
    }
}

void factors(ll n) {
    map<ll,ll> f;
    //cout << "factores: ";
    for (ll x = 2; x*x <= n; x++) {
        //cout << x << " ";
        if(ok){
            break;
        }
        while (n%x == 0 && !ok) {
            if(f.count(x)<1){
                f[x]++;
                factores_primos[x]++;
                if(factores_primos[x]>1){
                    ok=true;
                }
            }
            n /= x;
        }
    }
    if (n > 1){
        f[n]++;
        factores_primos[n]++;
        if(factores_primos[n]>1){
            ok=true;
        }
    }
    //cout << '\n';
}

int main() {
    int t;
    cin >> t;
    while(t--){
        map<ll,ll> P;
        ll maxx=0;
        int n;
        cin >> n;
        ok=false;
        factores_primos.clear();
        fr(0,n,i){
            ll nm;
            cin >> nm;
            if(ok){
                continue;
            }
            //cout << "numero: "<<nm<<'\n';
            //factors(nm);
            bool es_primo = MillerRabin(nm);
            if(es_primo){
                factores_primos[nm]++;
                if(factores_primos[nm]>1){
                    ok=true;
                }
            }else{
                trial_division3(nm);
            }
        }
        if(ok){
            cout << "YES\n";
        }else{
            cout << "NO\n";
        }
    }
    return 0;
}