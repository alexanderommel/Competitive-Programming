// Online C++ compiler to run C++ program online
#include <bits/stdc++.h>
#define ll long long
using namespace std;

ll m=1e12;

int main() {
    int t;
    cin >> t;
    while(t--){
        string s;
        cin >> s;
        int n = s.size();
        int o=0;
        int z=0;
        int a[n]; //ones left
        int b[n]; //zeros right
        for(int i=0;i<n;i++){
            if(s[i]=='0'){
                z++;
            }else{
                o++;
            }
            a[i]=o;
        }
        o=0;
        for(int i=0;i<n;i++){
            if(s[i]=='0'){
                o++;
            }
            b[i]=z-o;
        }
        for(int i=0;i<n;i++){
            //cout << a[i] << " "<< b[i] <<'\n';
        }
        ll ans=(m+1)*z;
        for(int i=0;i<n;i++){
            if(i<n-1){
                if(s[i]=='1' && s[i+1]=='0'){
                    a[i]--;
                    b[i]--;
                    ll loc = m + (m+1)*(a[i]+b[i]);
                    ans = min(ans,loc);
                    a[i]++;
                    b[i]++;
                }else{
                    ll loc = (m+1)*(a[i]+b[i]);
                    ans = min(ans,loc);
                }
            }else{
                ans = min(ans,(m+1)*(a[i]));
            }
        }
        cout << ans <<'\n';
    }
    return 0;
}