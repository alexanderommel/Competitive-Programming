#include <bits/stdc++.h>
#define ll long long
using namespace std;

const int N = 3 + (1e6);
const int Ke= 2+ (1e6);
ll prepp[N];
const int LM=36;

int main(){
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        ll a[n];
        a[0]=0;
        int ans[n+1];
        for (int i = 0; i < n+1; ++i) {
            ans[i]=0;
        }
        ll cand=-1;
        for (int i = 1; i < n; ++i) {
            cin >> a[i];
            ll res = a[i]-a[i-1];
            if (res<=n && ans[res]==0){
                ans[res]=1;
            }else{
                cand = max(cand,res);
            }
        }
        int c=0;
        vector<int> d;
        for (int i = 1; i < n+1; ++i) {
            if (ans[i]==0){
                c++;
                d.push_back(i);
            }
        }
        if (c==1 && cand==-1){
            cout << "YES\n";
            continue;
        }
        if(c==2 && cand==d[0]+d[1]){
            cout << "YES\n";
            continue;
        }
        cout << "NO\n";
    }
}