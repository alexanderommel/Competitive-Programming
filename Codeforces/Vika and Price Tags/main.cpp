#include <bits/stdc++.h>
#define ll long long
using namespace std;

const int N = 3 + (1e6);
ll pre[N];

int main(){
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        ll a[n];
        ll b[n];
        for (int i = 0; i < n; ++i) {
            cin >> a[i];
        }
        for (int i = 0; i < n; ++i) {
            cin >> b[i];
        }
        if(n==1){
            cout << "YES\n";
            continue;
        }
        ll times[n];
        for (int i = 0; i < n; ++i) {
            if (a[i]==0 && b[i]==0){
                times[i]=-1;
                continue;
            }
            if (a[i]==0){
                times[i]=2;
                continue;
            }
            if(b[i]==0){
                times[i]=3;
                continue;
            }
            if (a[i]==b[i]){
                times[i]=1;
                continue;
            }
            ll a0 = 0;
            ll ai = a[i];
            ll bi = b[i];
            while(true){
                ll div = ai/bi;
                if (div>1){

                    ll jumps = div/2;
                    ll steps = jumps + jumps*2;
                    ll reducer = jumps * 2 * bi;
                    a0+=steps;
                    ai=ai-reducer;
                }else{
                    ll temp = abs(ai-bi);
                    ai=bi;
                    bi=temp;
                    a0++;
                }
                if (bi==0) break;
            }
            times[i]=a0;
        }
        bool ans=true;
        ll base = -1;
        ll zeros=0;
        for (int i = 0; i < n; ++i) {
            //cout << times[i]<<" ";
            if (times[i]==-1){
                zeros++;
            }else{
                if(base==-1){
                    base=times[i];
                }else{
                    ll k = (base-times[i])/3;
                    if (times[i]+3*k != base){
                        ans=false;
                        break;
                    }
                }
            }
        }
        //cout <<'\n';
        if (ans){
            cout << "YES\n";
        }else{
            cout << "NO\n";
        }
    }
}