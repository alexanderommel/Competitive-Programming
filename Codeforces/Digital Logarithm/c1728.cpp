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


int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        map<ll,ll, greater<ll>> ma;
        fr(0,2*n,i){
            ll num;
            cin >> num;
            if(i<n){
                ma[num]++;
                continue;
            }
            ma[num]--;
        }
        int ans=0;
        // por defecto los maps al iterar es ascendentemente, pero con el comparador hacemos que se descendente
        // si modificamos algun key, entonces este se agrega al map y el numero de iteraciones aumentara
        // el iterador siempre que sea posible va a retornar el elemento mas grande del mapa
        for(auto p:ma){
            ma[to_string(p.first).length()]+=p.second;
            ans+= abs(p.second);
        }

        cout << ans <<  '\n';

    }

    return 0;

}
