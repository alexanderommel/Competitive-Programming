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
    while(t--){
        int n,k;
        cin >> n >> k;
        ll a[n];
        for(int i=0;i<n;i++){
            cin >> a[i];
        }
        int ans=0;
        for(int i=0;i<k;i++){
            vector<ll> orden;
            for(int j=i;j<n;j+=k){
                orden.push_back(a[j]);
            }
            std::sort(orden.begin(), orden.end());
            int limite = (i+1)%k;
            for(int j=0;j<orden.size();j++){
                if(orden[j]%k!=limite){
                    ans++;
                }
            }
        }
        if(ans==0){
            cout << 0 <<'\n';
            continue;
        }
        if(ans==2){
            cout << 1 <<'\n';
            continue;
        }
        if(ans>2){
            cout << -1 <<'\n';
        }
    }
}