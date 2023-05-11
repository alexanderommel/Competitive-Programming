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
    ll a[15];
    a[0]=0;
    for(ll i=1;i<15;i++){
        ll z = pow(10,i);
        a[i]= (z/10) + (9*a[i-1] + 0LL);
    }
    for(int i =1; i<15;i++){
        ll z = pow(10,i);
        a[i] =  z - a[i];
        //cout << a[i]<<'\n';
    }
    while(t--){
        ll k;
        cin >> k;
        ll ans=0;
        int p=15;
        while(k>0){
            p--;
            if (k<a[p]) continue;
            if(k<10){
                ans+=k;
                if (k>3) ans++;
                k=0;
            }else{
                ll f = k / a[p];
                k = k - f*a[p];
                if (f>3) f++;
                ans+= f*pow(10,p) + 0LL;
            }
        }
        cout <<ans<<'\n';
    }

}