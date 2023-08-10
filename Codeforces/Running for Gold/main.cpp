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
        int a[n][5];
        int winner = 0;
        for (int i = 0; i < n; ++i) {
            bool ok=true;
            for (int j = 0; j < 5; ++j) {
                cin >> a[i][j];
            }
            if (i>0){
                int c=0;
                for (int j = 0; j < 5; ++j) {
                    if (a[winner][j]<a[i][j]) c++;
                }
                if (c<3) ok=false;
            }
            if (!ok) winner=i;
        }
        for (int i = 0; i < n && winner!=-2; ++i) {
            if (i==winner) continue;
            int c=0;
            for (int j = 0; j < 5; ++j) {
                if (a[winner][j]<a[i][j]) c++;
            }
            if (c<3) winner=-2;
        }
        cout << winner + 1 <<'\n';
    }
}