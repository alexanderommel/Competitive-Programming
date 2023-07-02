#include <bits/stdc++.h>
#define ll long long
using namespace std;

const int N = 101;
int dp[N];

int main(){
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        int a=0;
        int ans1=0;
        for (int i = 1; i <=n ; ++i) {
            int nm;
            cin >> nm;
            a+=nm;
            ans1=max(ans1,a);
        }
        int b=0;
        int ans2=0;
        int m;
        cin >> m;
        for (int i = 1; i <=m ; ++i) {
            int nm;
            cin >> nm;
            b+=nm;
            ans2=max(ans2,b);
        }
        cout << ans1 + ans2 <<'\n';
    }
}
