#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
const int maxN = 2e5;
int N, Q;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> N >> Q;
    int K = 30;
    int XOR[K+1][N+1];
    for (int i = 0; i < K + 1; ++i) {
        XOR[i][0]=0;
    }
    for (int i = 1; i <= N; ++i) {
        ll num; cin >> num;
        ll j,z=K;
        for (j = 1 << K; j > 0 ; j = j/2, z--) {
            if ((num & j) != 0) XOR[z][i]=1;
            else XOR[z][i]=0;
            XOR[z][i]+=XOR[z][i-1];
        }
    }
    while(Q--){
        int a,b; cin >> a >> b;
        ll num=0;
        for (int i = 0; i < K + 1; ++i) {
            int bits = XOR[i][b]-XOR[i][a-1];
            if (bits%2!=0){
                ll addon = 1 << i;
                num+=addon;
            }
        }
        cout << num<<'\n';
    }
}
