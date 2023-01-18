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

int main(){
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    int n,k;
    cin >> n >> k;
    int W[n+1];
    int P[n+1];
    int dp[k+1][n+1];

    W[0]=0;
    P[0]=0;

    fr(0,n+1,i){
        P[i]=0;
        W[i]=0;
        fr(0,k+1,j){
            dp[j][i]=0;
        }
    }

    fr(1,n+1,i){
        cin >> W[i];
    }

    fr(1,n+1,i){
        cin >> P[i];
    }

    fr(0,k+1,w){
        fr(1,n+1,i){
            if (W[i]>w){
                dp[w][i]=dp[w][i-1];
            }
            if (W[i]==w){
                dp[w][i]=max(dp[w][i-1],P[i]);
            }
            if (W[i]<w){
                dp[w][i]=max(dp[w][i-1],P[i]+dp[w-W[i]][n]);
            }
            cout << "dp[" << w << "]["<<i<<"] = "<<dp[w][i]<<'\n';
        }
    }

    cout << dp[k][n] << '\n';

    return 0;
}