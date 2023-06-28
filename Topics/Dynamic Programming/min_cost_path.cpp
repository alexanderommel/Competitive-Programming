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
* https://www.geeksforgeeks.org/min-cost-path-dp-6/
 * Given a cost matrix cost[][] and a position (m, n)
 * in cost[][], write a function that returns
 * cost of minimum cost path to reach (m, n) from (0, 0).
 * Each cell of the matrix represents a cost to traverse
 * through that cell.
*/


const int N=3,M=3;
int A[N][M]={{1,2,3},
             {4,8,2},
             {1,5,3}};
vector<vector<int>> memo(N,vector<int>(M,-1));

int dp(int n,int m){
    if (memo[n][m]!=-1){
        return memo[n][m];
    }
    if (n==0){
        memo[0][m-1]= A[0][m-1]+A[0][m];
        return memo[0][m-1];
    }
    if (m==0){
        memo[n-1][0]=A[n-1][0]+A[n][0];
        return memo[n-1][0];
    }
    int ans=A[n][m];
    ans += min(min(dp(n-1,m),dp(n,m-1)),dp(n-1,m-1));
    memo[n][m]=ans;
    return memo[n][m];
}

int main(){
    cout << dp(2,2);
}