#include <bits/stdc++.h>
#define ll long long
using namespace std;

const ll L=1;
const ll R = 1e13 +1;

int main(){
    int t;
    cin >> t;
    while(t--){
        string s;
        cin >> s;
        ll n = s.size();
        ll c=0;
        ll ans=0;
        ll first=0;
        bool iggnore=false;
        for (int i = 0; i < n; ++i) {
            if(s[i]=='1'){
                c++;
            }else{
                if (!iggnore){
                    first=c;
                }
                iggnore=true;
                ans=max(c,ans);
                c=0;
            }
        }
        ans=max(c+first,ans);
        ll le = ans;
        if (ans==n) ans=n*n;
        for (int i = 1; i < le; ++i) {
            ll rel = (long long) ((le-i)*(i+1));
            ans = max(ans,rel)  ;
        }
        cout << ans <<'\n';
    }
}