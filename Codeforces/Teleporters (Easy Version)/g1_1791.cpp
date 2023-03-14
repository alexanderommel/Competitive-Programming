#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define fr(s,n,i) for (long long i=s; i<n; ++i)


int main(){

    int t;
    cin >> t;
    while(t--){
        int n;
        ll c;
        cin >> n >> c;
        vector<ll> a;
        for(int i=1; i<=n; ++i){
            ll ai;
            cin >> ai;
            a.push_back(ai+i);
        }
        std::sort(a.begin(), a.end());
        int i=0;
        int ans=0;
        while(i<n){
            if(a[i]>c){
                break;
            }else{
                c-=a[i];
                ans++;
                i++;
            }
        }
        cout << ans <<'\n';
    }
}