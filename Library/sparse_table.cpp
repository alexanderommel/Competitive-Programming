#include<bits/stdc++.h>
#include <bit>
using namespace std;
#define ll long long

const int MAXN = 200001;
const int K = 25;
int tab[MAXN][K + 1];
int lg[MAXN+1];


int main(){

    lg[1] = 0;
    for (int i = 2; i <= MAXN; i++)
        lg[i] = lg[i/2] + 1;

    int n,m; cin >> n >> m;
    vector<int> a(n,0);
    for (int i = 0; i < n; ++i) cin >> a[i];

    for (int i = 0; i < n; ++i) {
        tab[i][0]=a[i];
    }


    for (int j = 1; j <= K; j++)
        for (int i = 0; i + (1 << j) <= n; i++)
            tab[i][j] = min(tab[i][j-1], tab[i + (1 << (j - 1))][j - 1]);


    while(m--){
        int R,L; cin >> L >> R;
        R--;
        L--;
        ll i = lg[R - L + 1];
        ll res = min(tab[L][i], tab[R - (1 << i) + 1][i]);
        cout << res << '\n';
    }

}
