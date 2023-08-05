#include <bits/stdc++.h>
#define ll long long
using namespace std;

const int N = 3 + (1e6);
ll pre[N];

int main(){
    int t;
    cin >> t;
    while(t--){
        int n,k;
        cin >> n >> k;
        map<int,int> f;
        for (int i = 0; i < n; ++i) {
            int nm;
            cin >> nm;
            f[nm]++;
        }
        int siz = 0;
        for(auto p: f){
            siz++;
        }
        if ((k>=siz) || (siz==1 && k==1)){
            cout << 1 <<'\n';
            continue;
        }
        if (k==1 && siz>1){
            cout << -1 <<'\n';
            continue;
        }
        int mod = ((siz-k)/(k-1));
        if ((siz-k)%(k-1)!=0) mod++;
        mod++;
        cout << mod <<'\n';
    }
}