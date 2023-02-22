#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define fr(s,n,i) for (long long i=s; i<n; ++i)
#define pb push_back
#define fri(s,e,i) for (long long i=s; i>=e; --i)

int main(){

    int t;
    cin >> t;
    while(t--)  {
        int n;
        cin >> n;
        ll a[n];
        ll b[n];
        fr(0,n,i)   {
            cin >> a[i];
        }
        fr(0,n,i)   {
            cin >> b[i];
        }
        map<ll,int> dfs;
        ll diferencia_mas_grande_zeros=0;
        ll prueba=0;
        bool ok=true;
        fr(0,n,i)   {
            ll d = a[i]-b[i];
            if(d<0){
                ok=false;
                break;
            }
            if(b[i]==0){
                diferencia_mas_grande_zeros = max(diferencia_mas_grande_zeros,d);
            }else{
                dfs[d]++;
                prueba = d;
            }
        }
        ll cc=0;
        for(auto dd: dfs){
            cc++;
        }
        if(cc>1){
            ok = false;
        }else{
            if(cc==1){
                if(diferencia_mas_grande_zeros>prueba){
                    ok = false;
                }
            }
        }
        if(ok){
            cout << "YES\n";
        }else{
            cout << "NO\n";
        }
    }

}