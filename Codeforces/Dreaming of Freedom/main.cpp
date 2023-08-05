#include <bits/stdc++.h>
#define ll long long
using namespace std;

const int N = 3 + (1e6);
ll pre[N];

int main(){
    int t;
    cin >> t;
    while(t--){
        int n,m;
        cin >> n >> m;
        if (n==1 || m==1){
            cout << "YES\n";
            continue;
        }
        if (m>=n && n!=1 || (m<n && n%2==0)) cout << "NO\n";
        else{
            bool ans=true;
            for (int i = 3; i*i<=n ; ++i) {
                if (n%i==0 && i<=m){
                    ans= false;
                    break;
                }
            }
            if (ans) cout <<"YES\n";
            else cout << "NO\n";
        }
    }
}