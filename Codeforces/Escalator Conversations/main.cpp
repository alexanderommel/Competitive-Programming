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
        ll n,m,k,h;
        cin >> n >> m >> k >> h;
        ll d = n + m;
        ll e = h*8;
        ll f= 0;
        ll res[n];
        for (int i = 0; i < n; ++i) {
            cin >> res[i];
            d+=i;
            e+=d;
        }
        for (int i = 0; i < n; ++i) {
            if (abs(h-res[i]) && abs(h-res[i])%k == 0 && abs(h-res[i])<=(m-1)*k){
                f++;
                e+=f;
            }
        }
        cout << f <<'\n';

    }
}