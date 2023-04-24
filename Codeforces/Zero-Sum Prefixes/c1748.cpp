#include <bits/stdc++.h>
#define pb push_back
#define vi vector<int>
#define ll long long
#define vll vector<long long>
#define pll pair<ll,ll>
using namespace std;

int main() {

    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    int q;
    cin >> q;
    while(q--){
        int n;
        cin >> n;
        ll a[n+1];
        for(int i=0;i<n;i++){
            cin >> a[i];
        }
        a[n]=0;
        map<ll,int> ans;
        bool zero_back=false;
        int res=0;
        ll curr=0;
        int local=0;
        ans[0]=1;
        for(int i=0;i<=n;++i){
            if (zero_back){
                if (a[i]==0){
                    res+=(local+1);
                    local=0;
                    ans.clear();
                    ans[0]=1;
                    curr=0;
                }else{
                    local = max(local,ans[curr+a[i]]);
                    curr+=a[i];
                    ans[curr]++;
                }
            }else{
                if (a[i]==0){
                    zero_back=true;
                    local=0;
                    ans.clear();
                    curr=0;
                    ans[0]=1;
                    continue;
                }
                if(curr+a[i]==0){
                    res++;
                    ans.clear();
                    ans[0]=1;
                    curr=0;
                }else{
                    curr+=a[i];
                    ans[curr]++;
                }
            }
        }
        cout << res <<'\n';
    }
    return 0;
}
