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
        ll a[n];
        for(int i=0;i<n;i++)    {
            cin >> a[i];
        }
        int ans=n;
        if(n==1){
            cout << ans <<'\n';
            continue;
        }
        if(n==2){
            if(a[0]==a[1]) ans--;
            cout << ans <<'\n';
            continue;
        }
        int p = 2;
        ll b  = a[0];
        ll c = a[1];
        ll d = a[2];
        while(p<n){
            d = a[p];
            if(abs(b-c)+abs(c-d)==abs(b-d)){
                c = d;
                ans--;
            }else{
                b=c;
                c=d;
            }
            p++;
        }
        if(b==c) ans--;
        cout << ans<<'\n';
    }
}