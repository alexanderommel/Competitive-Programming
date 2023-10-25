#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
const int MAX = 1e3;
int N,M, Q;

ll S[MAX+1][MAX+1];

int main(){

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> N >> Q;
    M = N; // THIS CASE IS A SQUARE MATRIX
    for (int i = 0; i <= N; ++i) S[i][0]=0;
    for (int i = 0; i <= M; ++i) S[0][i]=0;
    for (int i = 1; i <= N; ++i) {
        for (int j = 1; j <= M; ++j) {
            char value; cin >>value;
            ll my_value = 0;
            if (value=='*') my_value = 1ll;
            S[i][j]=S[i-1][j] + S[i][j-1] - S[i-1][j-1] + my_value;
        }
    }
    while(Q--){
        int i1,j1,i2,j2; cin >> i1 >> j1 >> i2 >> j2; // corners of the square, upper left and bottom right
        ll sum = S[i2][j2] - S[i2][j1-1] - S[i1-1][j2] + S[i1-1][j1-1];
        cout << sum << '\n';
    }

}