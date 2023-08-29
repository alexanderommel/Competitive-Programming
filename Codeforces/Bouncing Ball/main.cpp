#include <bits/stdc++.h>
#define ll long long
using namespace std;

const int th = 40001;

int main(){
    int t;
    cin >> t;
    while(t--){

        int n,p,k;
        cin >> n >> p >> k;
        p--;
        string s;
        cin >> s;
        int x,y;
        cin >> x >> y;
        bool visited[n];
        for (int i = 0; i < n; ++i) {
            visited[i]=false;
        }
        ll ans=LONG_LONG_MAX;
        for (int i = p; i < n; ++i) {
            if (visited[i]) continue;
            int f = 0;
            int zeros = 0;
            for (int j = i; j < n; j+=k) {
                visited[j]=true;
                if (s[j]=='0') zeros++;
                f++;
            }
            f=0;
            for (int j = i; j < n; j+=k) {
                ll loc = (f*k + (i-p))*y;
                loc += zeros*x;
                if (s[j]=='0') zeros--;
                ans = min(ans,loc);
                f++;
            }
        }
        cout << ans <<'\n';
    }
}