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
 * Given an array of n integers, find the maximum-length sequence
 * of array elements that goes from left to right, and each element
 * in the sequence is larger than de previous element.
 *
 */

int a[8]={6,2,5,1,7,4,8,3};
int memo[9]={0,0,0,0,0,0,0,0,0};

int dp(int i){
    if(i==1){
        memo[1]=1;
        return 1;
    }
    if (memo[i]>0){
        return memo[i];
    }
    memo[i]=1;
    for(int k=1;k<i;++k){
        int llls = dp(k);
        if (a[i-1]>a[k-1]){
            memo[i] = max(memo[i],llls+1);
        }
    }
    return memo[i];
}

int main(){
    dp(8);
    int ans = 0;
    fr(0,9,l){
        ans = max(ans,memo[l]);
    }
    cout << ans;
    return 0;
}