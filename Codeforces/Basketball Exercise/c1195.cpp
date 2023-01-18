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

const int N=10e5;
ll dp[N+1][4];
ll v[4][N+1];

int main(){
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    int n;
    cin >> n;
    fr(0,N+1,i){
        v[0][i]=0;
        v[1][i]=0;
        v[2][i]=0;
        v[3][i]=0;
        fr(0,4,j){
            dp[i][j]=0;
        }
    }

    fr(1,n+1,i){
        cin >> v[3][i];
    }
    fr(1,n+1,i){
        cin >> v[2][i];
    }

    fr(1,n+1,i){
        fr(0,4,j){
            if (j==0 || j==3){
                dp[i][j]=v[j][i]+max(dp[i-1][0],dp[i-1][2]);
            }else{
                dp[i][j]=v[j][i]+max(dp[i-1][1],dp[i-1][3]);
            }
        }
    }

    cout << max(dp[n][0], max(dp[n][1], max(dp[n][2],dp[n][3]))) << '\n';

    return 0;
}