#include <bits/stdc++.h>
#define ll long long
using namespace std;

const int N = 3 + (1e6);
ll pre[N];

int main(){
    int t;
    cin >> t;
    while(t--){
        ll n,h;
        cin >> n >> h;
        ll dp[n+1][6];
        vector<ll> a(n+1);
        a[0]=0;
        for (int i = 1; i <= n; ++i) {
            cin >> a [i];
        }
        std::sort(a.begin(), a.end());
        dp[0][0]=h;
        dp[0][1]=3*h;
        dp[0][2]=2*h;
        dp[0][3]=6*h;
        dp[0][4]=4*h;
        dp[0][5]=12*h;
        ll ans=0;
        for (int i = 1; i <=n ; ++i) {
            ll counter = 0;
            for (int j = 0; j < 6; ++j) {
                dp[i][j]=-1;
                if (j==0){
                    if(dp[i-1][0]>a[i]){
                        counter++;
                        dp[i][j]=dp[i-1][0]+(a[i]/2);
                    }
                }
                if (j==1){
                    if(dp[i-1][0]>a[i]){
                        counter++;
                        dp[i][j]=3*(dp[i-1][0]+(a[i]/2));
                    }
                    if(dp[i-1][1]>a[i]){
                        counter++;
                        dp[i][j] = max(dp[i][j],dp[i-1][1]+(a[i]/2));
                    }
                }
                if (j==2){
                    if(dp[i-1][0]>a[i]){
                        counter++;
                        dp[i][j]=2*(dp[i-1][0]+(a[i]/2));
                    }
                    if(dp[i-1][2]>a[i]){
                        counter++;
                        dp[i][j] = max(dp[i][j],dp[i-1][2]+(a[i]/2));
                    }
                }
                if (j==3){
                    if(dp[i-1][0]>a[i]){
                        counter++;
                        dp[i][j]=6*(dp[i-1][0]+(a[i]/2));
                    }
                    if(dp[i-1][1]>a[i]){
                        counter++;
                        dp[i][j] = max(dp[i][j],2*(dp[i-1][1]+(a[i]/2)));
                    }
                    if(dp[i-1][2]>a[i]){
                        counter++;
                        dp[i][j] = max(dp[i][j],3*(dp[i-1][2]+(a[i]/2)));
                    }
                    if(dp[i-1][3]>a[i]){
                        counter++;
                        dp[i][j]=max(dp[i][j],dp[i-1][3]+(a[i]/2));
                    }
                }
                if (j==4){
                    if(dp[i-1][0]>a[i]){
                        counter++;
                        dp[i][j]=4*(dp[i-1][0]+(a[i]/2));
                    }
                    if(dp[i-1][2]>a[i]){
                        counter++;
                        dp[i][j] = max(dp[i][j],2*(dp[i-1][2]+(a[i]/2)));
                    }
                    if(dp[i-1][4]>a[i]){
                        counter++;
                        dp[i][j]=max(dp[i][j],dp[i-1][4]+(a[i]/2));
                    }
                }
                if (j==5){
                    if(dp[i-1][0]>a[i]){
                        counter++;
                        dp[i][j]=12*(dp[i-1][0]+(a[i]/2));
                    }
                    if(dp[i-1][1]>a[i]){
                        counter++;
                        dp[i][j] = max(dp[i][j],4*(dp[i-1][1]+(a[i]/2)));
                    }
                    if(dp[i-1][2]>a[i]){
                        counter++;
                        dp[i][j] = max(dp[i][j],6*(dp[i-1][2]+(a[i]/2)));
                    }
                    if(dp[i-1][3]>a[i]){
                        counter++;
                        dp[i][j] = max(dp[i][j],2*(dp[i-1][3]+(a[i]/2)));
                    }
                    if(dp[i-1][4]>a[i]){
                        counter++;
                        dp[i][j] = max(dp[i][j],3*(dp[i-1][4]+(a[i]/2)));
                    }
                    if(dp[i-1][5]>a[i]){
                        counter++;
                        dp[i][j]=max(dp[i][j],dp[i-1][5]+(a[i]/2));
                    }
                }
                //cout << "dp["<<i<<","<<j<<"]="<<dp[i][j]<<'\n';
            }
            //cout << "number: "<<a[i]<<"    with counter: "<<counter<<'\n';
            if (counter==0) break;
            ans++;
        }
        cout << ans <<'\n';
    }
}