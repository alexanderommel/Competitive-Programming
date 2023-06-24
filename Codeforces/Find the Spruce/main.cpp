#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main(){
    int t;
    cin >> t;
    while(t--){
        int n,m;
        cin >> n  >> m;
        int a[n][m];
        bool b[n][m];
        int g1[n][m];
        int g22[n][m];
        for (int i = 0; i < n; ++i) {
            string s;
            cin >> s;
            int l=0;
            int r=0;
            for (int j = 0; j < m; ++j) {
                b[i][j]=true;
                g1[i][j]=l;
                if (s[j]=='*'){
                    a[i][j]=1;
                    l++;
                }else{
                    a[i][j]=0;
                    l=0;
                }
            }
            for (int j = m-1; j >=0 ; --j) {
                g22[i][j]=r;
                if (s[j]=='*'){
                    r++;
                }else{
                    r=0;
                }
            }
        }

        int ans=0;
        for (int h = 1; h <=n ; ++h) {
            for (int i = 0; i < n-h+1; ++i) {
                for (int j = 0; j < m; ++j) {
                    if (b[i][j] && a[i][j]==1){
                        int new_r = i + h -1 ;
                        if (g1[i+h-1][j]>=h-1 && g22[i+h-1][j]>=h-1 && a[i+h-1][j]==1){
                            ans++;
                            b[i][j]=true;
                        }else{
                            b[i][j]=false;
                        }
                    }
                }
            }
            //cout << "ans with h of "<<h<<" is: "<<ans<<'\n';
        }
        cout << ans <<'\n';
    }
}