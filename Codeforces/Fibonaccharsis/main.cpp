#include <bits/stdc++.h>
#define ll long long
using namespace std;

const int N = 3 + (1e6);
const int Ke= 2+ (1e6);
ll prepp[N];
const int LM=36;

int main(){
    int t;
    cin >> t;
    while(t--){
        ll n,k;
        cin >> n >> k;
        ll ans=0;
        // cout << 0 <<'\n' ;
        bool ok= true;
        if (k>37){
            ok = false;
            cout << 0 <<'\n';
            continue;
        }
        if (ok){
        }
        ll res[LM];
        for (int i = 0; i <= LM-1; ++i) {
            res[i]=1;
        }
        for (int i = 2; i <= LM-1; ++i) {
            res[i]=res[i-2]+res[i-1];
        }
        int c =0;
        for (int i = 0; i < n+1; ++i) {
            ll cond = n-(res[k-2]*i);
            if ((cond)%(res[k-3])==0 && cond >= 0 && k<=37){
                ll div = res[k-3];
                cond = cond / div;
                if (cond<=i){
                    ans++;
                    c++;
                    ok=true;
                }else{
                    c--;
                }
            }else{
                c--;
            }
        }
        cout << ans <<'\n';
    }
}