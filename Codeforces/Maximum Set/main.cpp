#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main(){
    int t;
    cin >> t;
    while(t--){
        ll l,r;
        cin >> l >> r;
        int i=1;
        ll factor = 2;
        while (l*factor<=r){
            i++;
            factor*=2;
            //cout << factor <<'\n';
        }
        int siz = i;
        ll L=l;
        ll R=2*L;
        ll limit;
        while(L<=R){
            ll x = (L+R)/2;
            int j = 1;
            factor = 2;
            while(x*factor<=r){
                j++;
                factor*=2;
            }
            if (j==siz){
                limit = x;
                L = x+1;
            }else{
                R = x -1;
            }
        }
        //cout << "limit: "<<limit<<'\n';
        L = l;
        R = limit;
        ll part=L-1;
        while(L<=R && siz>1){
            ll x = (L+R)/2;
            ll k = 1;
            for (int j = 0; j < siz-2; ++j) {
                k*=2;
            }
            if (x*k*3<=r){
                part = x;
                L = x+1;
            }else{
                R = x-1;
            }
        }
        //cout << "breaks on: "<<part<<'\n';
        ll ans = siz*(1+part-l);
        ans = ans + (limit-part);
        if (siz==1) ans = r - l + 1;
        cout << siz << " "<< ans <<'\n';
    }
}