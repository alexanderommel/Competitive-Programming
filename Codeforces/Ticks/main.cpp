#include <bits/stdc++.h>
#define ll long long
using namespace std;

const int N = 3 + (1e6);
ll pre[N];

int main(){
    int t;
    cin >> t;
    while(t--){
        int n,m,k;
        cin >> n >> m >> k;
        int a[n][m];
        int mask[n][m];
        for (int i = 0; i < n; ++i) {
            string s;
            cin >> s;
            for (int j = 0; j < m; ++j) {
                if (s[j]=='.'){
                    a[i][j]=0;
                    mask[i][j]=0;
                }else{
                    a[i][j]=1;
                    mask[i][j]=1;
                }
            }
        }
        for (int i = n-1; i >=0 ; --i) {
            for (int j = 0; j < m; ++j) {
                int c=0;
                for (int l = 1; j-l>=0 && j+l<=m-1 && i-l>=0 && a[i][j]==1; ++l) {
                    if (a[i-l][j-l]==1 && a[i-l][j+l]==1) c++;
                    else break;
                }
                for (int l = 0; l<=c && c>=k; ++l) {
                    mask[i-l][j-l]=0;
                    mask[i-l][j+l]=0;
                }
            }
        }
        bool ans=true;
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                if (mask[i][j]==1){
                    ans=false;
                    break;
                }
            }
        }
        if (ans) cout << "YES\n";
        else cout << "NO\n";
    }
}