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

/**
* Given an integer array of coins[ ] of size N representing different
 * types of currency and an integer sum, The task is to find the number
 * of ways to make sum by using different combinations from coins[].
*/

//int sum=4;
//int n=3;
int coins[] = { 1, 2, 3 };

// Recursivo
int dp(int sum, int n){
    if(sum==0){
        return 1;
    }
    if (sum<0){
        return 0;
    }
    if (n==0){
        return 0;
    }
    return dp(sum,n-1) + dp(sum-coins[n-1],n);
}

// Bottom-up con memoization sum+1 x n
int bt(int sum, int n){
    // Las filas representan las sumas posibles
    // Las columnas representan la cantidad de veces que se puede obtener esa suma usando a lo más cj monedas
    // Se asigna 1 porque significa que hay una moneda c tal que s-c=0, por lo que incluimos ese resultdo
    int memoization[sum+1][n];
    fr(0,n,i){
        memoization[0][i]=1;
    }
    for(int s=1;s<=sum;s++){
        for(int c=0;c<n;c++){
            // Puedo obtener una suma s, sumando una moneda c con todas las combinaciones de monedas
            // (hasta máximo c monedas) cuya suma es igual a s-c, siempre y cuando s-c>=0
            int x = (s-coins[c]>=0)?memoization[s-coins[c]][c]:0;
            // Como la columna representa la cantidad de sumas que podemos obtener usando hasta c monedas
            // entonces considermos las sumas que podemos obtener usando menos monedas
            int y = (c>=1)?memoization[s][c-1]:0;
            memoization[s][c]=x+y;
        }
    }
    return memoization[sum][n-1];
}

//Bottom-Up con memoización sum + 1 x n
//Como las monedas se pueden repetir, entonces solo nos interesa el último resultado,
//Por lo que para cualquier s, solo se almacenara el ultimo valor mas grande

int bu_short(int suma, int n){
    //Cada columna guarda la maxima combinacion de monedas tal que su suma es igual a si
    int memo[suma+1];
    memset(memo,0,sizeof (memo));
    memo[0]=1;
    fr(1,suma+1,s){
        int maxx=0;
        for(int c=0;c<n;c++){
            int x= (s-coins[c]>=0)?memo[s-coins[c]]:0;
            maxx+=x;
            //maxx = max(maxx,x);
        }
        int y =0;
        if (s>1){
            //y = memo[s-1];
        }
        cout << "for s: " << s << '\n';
        memo[s]=y+maxx;
        cout << "max: " << memo[s] << '\n';
    }
    return memo[suma];
}

int main(){
    cout << bu_short(4,3);
    return 0;
}