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
 * Given a rod of length n inches and an array of prices
 * that includes prices of all pieces of size smaller than n.
 * Determine the maximum value obtainable by cutting up
 * the rod and selling the pieces.
 */

const int n=8;
int p[n+1]={0,1,5,8,9,10,17,17,20};
int memo[n+1]={0,1,0,0,0,0,0,0,0};

int dp(int i){
    cout << "i: " <<i << '\n';
    if (i==1){
        return p[1];
    }
    if (memo[i]!=0){
        return memo[i];
    }
    int optimal=p[i];
    for(int k=1;k<i;++k){
        optimal = max(optimal,dp(k)+p[i-k]);
    }
    cout << "num: " << i << '\n';
    cout << "op´: " << optimal << '\n';
    memo[i] = optimal;
    return memo[i];
}

int main(){

    //C[i]=max(C[i-1]+p[1],p[i])
    dp(8);
    cout << memo[8] << '\n';
    return 0;
}
