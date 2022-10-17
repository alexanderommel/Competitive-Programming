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
 * Given a list of weights [1,3,3,5], determine all sums that can be
 * constructed using the weights.
 * @return
 */

int main(){
    int W[4]={1,3,3,5};
    bool possible[13][5];
    possible[0][0]=true;
    fr(0,13,x){
        fr(0,5,k){
            possible[x][k]=false;
            if (x==0){
                possible[x][k]=true;
                continue;
            }
            if (k==0){
                possible[x][0]=false;
                continue;
            }
            if (x-W[k-1]>=0){
                possible[x][k] |= possible[x-W[k-1]][k-1];
            }
            possible[x][k] |= possible[x][k-1];
        }
    }
    fr(0,13,i){
        if (possible[i][4]){
            cout << i << '\n';
        }
    }
}