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
typedef map<ll,ll, greater<ll>> desc_map; // mapa que al iterar empezamos desde el key mas grande
typedef std::pair<ll,ll> mypair; // equivale a pair<long long int, long long int>
typedef std::priority_queue<ll> maxqueue; // cola de prioridad (el mas grande arriba)
typedef std::priority_queue <ll, vector<ll>, greater<ll>> minqueue; // cola de prioridad menor (el menor arriba)

/**
 * UTILIDADES
 */

/** BUSQUEDAS **/

// debe estar ordenada de menor a mayor (ascendentemente la lista)
int busqueda_binaria(vector<long long int> lista,long long int objetivo, int left, int right){

    while(left<=right){
        int x = (left+right)/2;
        if(lista[x]==objetivo){
            return x; // si existe el numero retorna la posicion
        }
        if(lista[x]<objetivo){
            left = x+1;
        }else{
            right = x-1;
        }
    }
    return -1; // si no existe el numero
}
// debe estar ordenado de menor a mayor considerando el pair.first, el pair.second se ignora
int busqueda_binaria_pair(vector<mypair> a , ll num, int l, int r){ while(l<=r){ int x = (l+r)/2; if(a[x].first==num){return x;} if(a[x].first<num){l = x+1;}else{r = x-1;} } }


/** COMPARADORES PARA ORDENAR LISTAS **/
// segun el tipo de parametro se pueden modificar

bool comparador_descendente_normal ( const long long int& l, const long long int& r){ return l > r; }
bool comparador_ascendente_normal ( const long long int& l, const long long int& r){ return l < r; }
bool comparador_descendente_pair ( const mypair& l, const mypair& r){ return l.first > r.first; }
bool comparador_ascendente_pair ( const mypair& l, const mypair& r){ return l.first > r.first; }
bool comparador_ascendente_pair_string ( const pair<string,int>& l, const pair<string,int>& r){ return l.second > r.second; }

/** MAPAS **/

// Al iterar un map por defecto la iteración se realiza en orden ascendente con respecto a las keys del map

// funcion para ordenar un map de menor a mayor segun los values del map
// lo que hace es recibir un mapa, copiarlo en un vector de pairs y ordenar segun el valor 'value' del map
vector<mypair> ordenar_map(map<ll,ll> mapa){
    vector<mypair> a;
    for(auto e: mapa){ a.pb({e.second,e.first}); } // el e.second es el valor "value" del elemento del mapa
    sort(a.begin(), a.end(), comparador_ascendente_pair); return a;
}

// funcion similar para ordenar un mapa donde las keys son strings y los values son integers
vector<pair<string,int>> ordenar_mapa_strings(map<string,int> mapa){
    vector<pair<string,int>> a;
    for(auto e: mapa){
        a.push_back({e.first,e.second});
    }
    sort(a.begin(), a.end(), comparador_ascendente_pair_string);
    return a;
}

/** MATEMATICAS **/

// MAXIMO COMUN DIVISOR
int gcd(int a, int b){
    if(b==0)
        return a;
    return gcd(b,a%b);
}
// MINIMO COMUN MULTIPLO
int lcm(int a, int b){return (a*b)/(gcd(a,b));}


/**
 *  AQUÍ TERMINA
 */

int main(){

    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0); // no prestar atención, solo es para optimización de tiempos

    vector<mypair> a;
    vector<pair<long long int, long long int>> b; // es lo mismo de arriba
    a.pb({0,1});
    a.push_back({2,1});
    a.pb({12,1});
    a.pb({4,1});
    a.pb({3,1});
    a.pb({133,1});
    a.pb({1,1});

    std::sort(a.begin(), a.end(), comparador_ascendente_pair);

    fr(0,a.size(),i){
        cout << a[i].first << " ";
    }

    return 0;
}
