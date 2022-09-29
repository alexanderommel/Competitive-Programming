#include <iostream>
#include <vector>
#include <math.h>
#include <string>
#include <cstdlib>
#include <algorithm>
#include <map>
#define fr(size, i) for (int i=0; i<size; i++)
#define ff(size) for (int i = 0; i < size; i++)
#define ll long long
#define vll vector<long long >
#define pb push_back
#define vllin(vec,n) ff(n){ll x; cin>>x; vec.pb(x);}
#define vec_reversrt(vec) sort(vec.begin(), vec.end(), greater<>())

using namespace std;

int solucion(vll precios, vll presupuestos){
    vll diferencias;
    fr(precios.size(),i){
        diferencias.push_back(presupuestos[i]-precios[i]);
    }
    sort(diferencias.begin(), diferencias.end());
    vll negativos;
    vll positivos;
    fr(diferencias.size(),i){
        if(diferencias[i]<0){
            negativos.push_back(diferencias[i]);
        } else{
            positivos.push_back(diferencias[i]);
        }
    }
    vec_reversrt(negativos);
    int j=0;
    int compensable_pairs = 0;
    int not_compensables = 0;
    fr(positivos.size(),i){
        if (j>=negativos.size() || (positivos[i]<(negativos[j]*(-1)))){
            not_compensables+=1;
        }else{
            compensable_pairs+=1;
            j+=1;
        }
    }
    int max_groups = compensable_pairs + (not_compensables/2);
    return max_groups;
}

int main() {
    ll t=0;
    cin >> t;
    while(t--){
        ll n = 0;
        cin >> n;
        vll costos;
        vll presupuestos;
        vllin(costos,n);
        vllin(presupuestos,n);
        cout << solucion(costos,presupuestos) << endl;
    }
}