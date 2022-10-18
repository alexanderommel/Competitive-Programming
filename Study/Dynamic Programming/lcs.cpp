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
string a="AGGTAB";
string b="GXTXAYB";
const int N=6;
const int M=7;
//int memo[N+1][M+1];

vector<vector<int> > memo(N + 1, vector<int>(M + 1, -1));

/**
 * LCS Problem Statement: Given two sequences, find the length of longest subsequence
 * present in both of them.
 * A subsequence is a sequence that appears in the same relative order,
 * but not necessarily contiguous.
 * For example, “abc”, “abg”, “bdf”, “aeg”, ‘”acefg”, .. etc are subsequences of “abcdefg”.
 */

/**
 * Empezando desde la derecha:
 * Cada vez que encontremos un caracter igual, siempre nos aumenta en 1 el resultado final.
 * Cuando dos caracteres no coinciden entonces se generan dos posibles LS, entonces elegiremos
 * la mejor LS de las dos posibles y asi recursivamente.
 * Este enfoque es de fuerza bruta ya que consideramos todas las subsecuencias posibles,por ejemplo
 * Si dos caracteres en los indices n-1,m-1 no coinciden,
 * entonces podemos reducir el puntero del string b hasta llegar a 0,
 * es decir que estariamos comparando A[n-1]^B[m-2],A[n-1]^B[m-3]***A[n-1]B[0],otras combinaciones posibles
 * son A[n-2]^B[m-2],A[n-2]^B[m-3]***A[n-2]B[0] (Fuerza Bruta).
 */

int dp(int n,int m){
    if (n==0 || m==0){
        memo[n][m]=0;
        return 0;
    }
    if (memo[n][m]!=-1){
        return memo[n][m];
    }
    if (memo[n][m])
    if (a[n-1]==b[m-1]){
        memo[n][m]=1+dp(n-1,m-1);
    }else{
        memo[n][m]=max(dp(n,m-1),dp(n-1,m));
    }
    return memo[n][m];
}

int main(){
    cout << dp(N,M);
}
