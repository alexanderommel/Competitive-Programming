#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main(){
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        ll a[n];
        for (int i = 0; i < n; ++i) {
            cin >> a[i];
        }
        ll c[n];
        c[n-1]=0;
        for (int i = n-2; i >=0 ; --i) {
            c[i]=c[i+1]+abs(a[i]-a[i+1]);
        }
        ll b[n];
        for (int i = n-1; i >=0; --i) {
            if (i==n-1){
                b[n-1]=abs(a[n-1]-a[n-2]);
                continue;
            }
            if(i==0){
                b[0]=c[0]-c[1];
                continue;
            }
            if ((a[i-1]>=a[i] && a[i]>=a[i+1]) || (a[i-1]<=a[i] && a[i]<=a[i+1])){
                b[i]=0;
            }else{
                //b[i]=abs(a[i-1]-a[i])+abs(a[i]-a[i+1]);
                b[i]=c[i-1]-(c[i+1]+abs(a[i-1]-a[i+1]));
            }
        }
        int k;
        ll ans=0;
        for (int i = 0; i < n; ++i) {
            if(b[i]>=ans){
                ans=b[i];
                k=i;
            }
        }
        ans=0;
        for (int i = n-1; i >=0; --i) {
            if(i==k){
                if(i>0){
                    a[i]=a[i-1];
                }else{
                    a[0]=a[1];
                }
                break;
            }
        }
        for (int i = n-1; i >0 ; --i) {
            ans+=(abs(a[i]-a[i-1]));
        }
        cout << ans <<'\n';
    }
}