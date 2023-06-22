#include <bits/stdc++.h>
#define pb push_back
#define vi vector<int>
#define ll long long
#define vll vector<long long>
#define pll pair<ll,ll>
using namespace std;
typedef std::tuple<int,int,int> mytuple;


#include <bits/stdc++.h>
#define pb push_back
#define vi vector<int>
#define ll long long

using namespace std;

int main(){
    int t;
    cin >> t;
    while(t--){
        int n,q;
        cin >> n >> q;
        ll m[1002][1002];
        for (int i = 0; i < 1002; ++i) {
            for (int j = 0; j < 1002; ++j) {
                m[i][j]=0L;
            }
        }
        for (int i = 0; i < n; ++i) {
            int a,b;
            cin >> a >> b;
            m[a][b]+=(a*b);
        }
        for (int i = 1; i < 1000+2; ++i) {
            for (int j = 1; j < 1000+2; ++j) {
                m[i][j] = m[i][j-1] + m[i][j];
            }
            for (int j = 1; j < 1000+2; ++j) {
                m[i][j] = m[i-1][j] + m[i][j];
            }
        }
        while(q--){
            int l,r,L,R;
            cin >> l >> r >> L >> R;
            long long ans = m[L-1][R-1]-m[L-1][r]-m[l][R-1]+m[l][r];
            cout <<ans<<'\n';
        }
    }
}