#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define fr(s,n,i) for (long long i=s; i<n; ++i)
#define fri(s,e,i) for (long long i=s; i>=e; --i)

int O[2003];

int main(){

    fr(1,1001,i){
        O[i]=INT_MAX;
    }
    O[1]=0;
    fr(1,1001,i){
        fr(1,i+1,j){
            int s = i + (i/j);
            if(O[s]==INT_MAX){
                O[s]=O[i]+1;
            }else{
                O[s]=min(O[s],O[i]+1);
            }
        }
    }

    int t;
    cin >> t;
    while(t--){
        ll n,k;
        cin >> n >> k;
        int b[n];
        fr(1,n+1,i){
            int nm;
            cin >> nm;
            b[i-1]=O[nm];
        }
        int c[n];
        fr(0,n,i){
            cin >> c[i];
        }
        // ASUMIMOS QUE EXISTE A LO MAS 10E5 operaciones
        ll W = 1e5;
        W = min(W,k);
        ll dp[W+1];
        ::memset(dp,0,sizeof (dp));
        fr(1,n+1,i){
            fri(W,0,w){
                if(b[i-1]<=w){
                    dp[w]=max(dp[w],dp[w-b[i-1]] + c[i-1]);
                }
            }
        }
        cout << dp[W]<<'\n';
    }
}