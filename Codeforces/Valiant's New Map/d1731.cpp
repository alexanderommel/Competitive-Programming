#include<bits/stdc++.h>
using namespace std;
#define ll long long

int main(){
    int t;
    cin >> t;
    while(t--){
        int n,m;
        cin >>n >> m;
        int A[n+1][m+1];
        for(int i=1;i <=n; ++i){
            for(int j=1; j<=m; ++j){
                cin >> A[i][j];
            }
        }
        int L=1; int R=n;
        int ans=0;
        while(L<=R){
            bool ok = false;
            int X = (L+R)/2;
            //cout << '\n'<< "Tamano: "   <<X<<'\n'   ;
            int S[n+1][m+1];
            for(int i=0; i<=n; ++i){
                S[i][0] = 0;
            }
            for(int i=0; i<=m; ++i){
                S[0][i]=0;
            }
            for(int i=1; i<=n;++i){
                for(int j=1; j<=m; ++j){
                    S[i][j] = S[i][j-1] + ((A[i][j]<X)?1:0);
                }
                for(int j=1; j<=m; ++j){
                    S[i][j] = S[i-1][j] + S[i][j];
                    //cout << S[i][j]<<" ";
                }
                //cout << '\n';
            }
            for(int i=1; i<=(n-X+1);++i){
                if(ok){
                    break;
                }
                for(int j=1; j<=(m-X+1);++j){
                    //cout << "P("<<i<<","<<j<<"): ";
                    int total = S[i+X-1][j+X-1] - S[i-1][j+X-1] - S[i+X-1][j-1] + S[i-1][j-1];
                    //cout << total << '\n';
                    if(total<=0){
                        ok = true;
                        break;
                    }
                }
            }
            if(ok){
                ans = X;
                L=X+1;
            }else{
                R=X-1;
            }
        }
        cout << ans << '\n';
    }
}