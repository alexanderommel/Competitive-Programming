#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define fr(s,n,i) for (long long i=s; i<n; ++i)
#define fri(s,e,i) for (long long i=s; i>=e; --i)

int main(){
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        ll S[n+1];
        S[0]=0;
        bool DP[3][n+1];
        for(int i=1; i<=n; ++i){
            cin >> S[i];
            DP[0][i]=false;
            DP[1][i]=false;
            DP[2][i]=false;
        }
        DP[0][0]=true;
        DP[1][0]=false;
        DP[2][0]=true;
        fr(1,n+1,i){
            if(DP[0][i-1] || DP[2][i-1]){
                if(i+S[i]<=n){
                    DP[0][i+S[i]]=true;
                    DP[1][i]=true;
                }
            }
            if(i-S[i]-1>=0){
                if(DP[0][i-S[i]-1] || DP[2][i-S[i]-1]){
                    DP[2][i]=true;
                }
            }
        }
        bool yes=false;
        if(DP[0][n] || DP[2][n]){
            yes=true;
        }
        if(yes){
            cout << "YES\n";
        }else{
            cout << "NO\n";
        }
    }
}