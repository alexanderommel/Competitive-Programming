#include <bits/stdc++.h>
#define ll long long
using namespace std;

const int N = 3 + (1e6);
ll pre[N];

int main(){
    int t;
    cin >> t;
    while(t--){
        int n,k;
        cin >> n >> k;
        int a[k+1];
        int ans[k+1];
        int pos[k+1];
        vector<int> c[k+1];
        for (int i = 1; i < k+1; ++i) {
            a[i]=0;
            ans[i]=-1;
            pos[i]=-1;
        }
        for (int i = 1; i <= n; ++i) {
            int ki;
            cin >> ki;
            c[ki].push_back(i-a[ki]-1);
            ans[ki]=max(ans[ki],i-a[ki]-1);
            a[ki]=i;
        }
        for (int i = 1; i < k+1; ++i) {
            if (a[i]!=0){
                c[i].push_back(n-a[i]);
                ans[i]=max(ans[i],n-a[i]);
            }
        }
        int res = INT_MAX;
        for (int i = 1; i < k+1; ++i) {
            if (ans[i]!=-1){
                std::sort(c[i].begin(), c[i].end());
                std::reverse(c[i].begin(), c[i].end());
                res=min(res,max(c[i][1],c[i][0]/2));
            }
        }
        cout << res <<'\n';
    }
}