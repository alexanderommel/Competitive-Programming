#include<bits/stdc++.h>
using namespace std;
#define ll long long

const ll mod = 1e9 + 7;
const ll M = 2e5+100;

ll DP[10][M];

void fillDp(){
    for(ll i=0; i<10; ++i){
        ll Q[10] = {0,0,0,0,0,0,0,0,0,0};
        Q[i]=1;
        for(ll j=1; j<M; ++j){
            bool jump=false;
            ll amount = 0;
            for(ll z=9; z>=0; --z){
                if(Q[z]>0){
                    if(z==9){
                        amount = Q[z];
                        Q[9]=0;
                        jump = true;
                    }else{
                        Q[z+1]=Q[z];
                        Q[z]=0;
                    }
                }
            }
            if(jump){
                Q[0]+=amount%mod;
                Q[1]+=amount%mod;
            }
            ll sum = 0;
            for(long long k : Q){
                sum+=(k%mod);
            }
            DP[i][j]=sum%mod;
        }
    }
}

int main(){

    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    int t;
    cin >> t;
    bool first = true;
    while(t--){

        if(first){
            fillDp();
            first = false;
        }

        int n,m;
        cin >> n >> m;
        map<int,ll> F;
        ll ans = 0;
        for(char digit: to_string(n)){
            int digito = digit - '0';
            ans+=(DP[digito][m]%mod);
        }
        cout << ans % mod <<'\n';
    }
}