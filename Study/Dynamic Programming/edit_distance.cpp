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
* Given two strings str1 and str2 and below operations
 * that can be performed on str1.
 * Find minimum number of edits (operations) required to convert
 * ‘str1’ into ‘str2’.
    1. Insert
    2. Remove
    3. Replace
 * All of the above operations are of equal cost.
*/
string a="sunday";
string b="saturday";
int N=6;
int M=8;
vector<vector<int>> memo(N+1,vector<int>(M + 1, -1));

int dp(int n, int m){
    if (n==0 || m==0){
        memo[n][m] = abs(n-m);
        return memo[n][m];
    }
    if (memo[n][m]!=-1){
        return memo[n][m];
    }
    if (a[n-1]==b[m-1]){
        memo[n][m]=dp(n-1,m-1);
        //return dp(n-1,m-1);
    }else{
        int add = dp(n,m-1);
        int cut = dp(n-1,m);
        int replace = dp(n-1,m-1);
        int minimum = min(add,cut);
        minimum = min(minimum,replace);
        memo[n][m] = 1+minimum;
        //return 1 + minimum;
    }
    return memo[n][m];
}

int main(){
    cout << dp(N,M);
    return 0;
}