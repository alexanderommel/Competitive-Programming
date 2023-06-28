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
* Given this set of coins {1,3,4}.
 * 1. Find the minimal number of coins needed such that the sum of them
 * is equals to X=10.
 * 2. Show which coins are needed in order to satisfy the previous point.
 *
*/

int main(){
    int coins[3]={1,3,4};
    int n=10;
    int value[n+1];
    int first[n+1];
    value[0]=0;
    fr(1,n+1,x){
        value[x]=INFINITY;
        for(auto c: coins){
            if (x-c>=0 && value[x-c]+1<value[x]){
                value[x] = value[x-c]+1;
                first[x]=c;
            }
        }
    }
    cout << "Optimal solution for X="<<10<<" is " << value[10] << '\n';
    cout << "Path: " <<'\n';
    while(n>0){
        cout << first[n] << '\n';
        n-=first[n];
    }
    return 0;
}