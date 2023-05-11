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
        int n;
        cin >> n;
        int ans=0;
        int a[n];
        int local=0;
        for(int i=0;i<n;i++){
            cin >> a[i];
            if(a[i]==1){
                ans=max(ans,local);
                local=0;
            }else{
                local++;
            }
        }
        ans=max(ans,local);
        cout << ans<<'\n';
    }
}