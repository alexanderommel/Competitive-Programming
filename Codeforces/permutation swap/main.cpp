#include <bits/stdc++.h>
#define pb push_back
#define vi vector<int>
#define ll long long
#define vll vector<long long>
#define pll pair<ll,ll>
using namespace std;
typedef std::tuple<int,int,int> mytuple;

ll gcd(ll a,ll b){
    if(a==0){
        return b;
    }
    return gcd(b%a,a);
}

int main(){
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        ll a[n];
        int ans=-1;
        for(int i=0;i<n;i++){
            cin >> a[i];
            if(i==0){
                ans= abs(a[i]-(i+1));
            }else{
                ans = gcd(ans,abs(a[i]-(i+1)));
            }
        }
        cout << ans <<'\n';
    }
}