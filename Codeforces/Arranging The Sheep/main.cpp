#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main(){
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        string g;
        cin >> g;
        string s = '.' + g + '.';
        ll c=0;
        ll z=0;
        ll suma=0;
        ll last=0;
        vector<ll> left;
        for (int i = 1; i < n+2; ++i) {
            if (s[i-1]=='*'){
                c++;
                if (s[i]=='.'){
                    last+=(z*suma);
                    left.push_back(last);
                    z=0;
                    suma+=c;

                }
            }else{
                c=0;
                z++;
            }
        }
        c=0;
        z=0;
        suma=0;
        last=0;
        vector<ll> right;
        std::reverse(s.begin(), s.end());
        for (int i = 1; i < n+2; ++i) {
            if (s[i-1]=='*'){
                c++;
                if (s[i]=='.'){
                    last+=(z*suma);
                    right.push_back(last);
                    z=0;
                    suma+=c;

                }
            }else{
                c=0;
                z++;
            }
        }
        std::reverse(right.begin(), right.end());
        if (left.size()<=1){
            cout << 0 <<'\n';
        }else{
            ll ans = LONG_LONG_MAX;
            for (int i = 0; i < left.size(); ++i) {
                ll loc = left[i]+right[i];
                ans=min(ans,loc);
            }
            cout << ans <<'\n';
        }

    }
}