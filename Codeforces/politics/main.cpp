#include <bits/stdc++.h>
#define pb push_back
#define vi vector<int>
#define ll long long
#define vll vector<long long>
#define pll pair<ll,ll>
using namespace std;
typedef std::tuple<int,int,int> mytuple;



int main(){
    int t;
    cin >> t;
    while(t--) {
        int n,k;
        cin >> n >> k;
        int a[n][k];
        for(int i=0;i<n;i++){
            string s;
            cin >> s;
            for(int j=0;j<k;j++){
                if(s[j]=='+'){
                    a[i][j]=1;
                }else{
                    a[i][j]=0;
                }
            }
        }
        int ans=1;
        int pre = n-1;
        map<int,int> fb;
        for(int i=0;i<k;i++){
            for(int j=1;j<n;j++){
                if(fb[j]>0){
                    continue;
                }else{
                    if (a[0][i]==0 && a[j][i]==1){
                        fb[j]++;
                        pre--;
                    }
                    if (a[0][i]==1 && a[j][i]==0){
                        fb[j]++;
                        pre--;
                    }
                }
            }
        }
        cout << ans + pre <<'\n';
    }
}
