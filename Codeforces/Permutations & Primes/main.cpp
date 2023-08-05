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
        if (n==1){
            cout << 1 <<'\n';
            continue;
        }
        int m;
        ll a[n];
        ll b[n];
        a[n-1]=3;
        a[0]=2;
        a[n/2]=1;
        for (int i = 1, k=4; i <= n-2; ++i) {
            if (i==(n/2)){
                continue;
            }
            a[i]=k;
            k++;
        }
        // cout << a[n-1];
        for (int i = 0; i < n; ++i) {
            cout << a[i]<< " ";
        }
        cout << '\n';
    }
}