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

void sol(int n, int k, string s){
    vector<int> F(29,0);
    fr(0,n,i){
        F[s[i]-'a']++;
    }
    int num_pairs=0;
    int num_ones=0;
    for(auto p: F){
        num_pairs+= p/2;
        num_ones+=p%2;
    }
    int ans = 0;
    // Verificamos si hay suficiente cantidad de pares para suplir a todos los k
    // grupos necesarios, de modo que la longitud mas larga será de al menos la
    // cantidad de pares por 2, esto es   2*num_pares/k
    ans = 2 *(num_pairs/k);
    // Como puede sobrar algunos pares que no se pueden agrupar perfectamente,
    // por ejemplo tenemos 5 pares y necesitamos 2 grupos, entonces tenemos
    // 2 grupos con dos pares y sobro un par, que podemos dividir en impares
    // y agregar a estos grupos
    num_ones+=2*(num_pairs%k);
    // Ahora, si tenemos impares sobrando mayor o igual a k (si son menores no
    // tiene sentido ya que la respuesta es imprimir la longitud del palindromo
    // mas pequeño de todos los mas grandes)
    if (num_ones>=k){
        ans++;
    }
    cout << ans << '\n';
}

int main(){
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    int t;
    cin >> t;
    while(t--){
        int n,k;
        cin >> n >> k;
        string s;
        cin >> s;
        sol(n,k,s);
    }

    return 0;
}


