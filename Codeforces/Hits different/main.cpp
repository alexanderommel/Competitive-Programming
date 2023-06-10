#include <bits/stdc++.h>
#define pb push_back
#define vi vector<int>
#define ll long long
#define vll vector<long long>
#define pll pair<ll,ll>
using namespace std;
typedef std::tuple<int,int,int> mytuple;

ll ans[2047277];

int main(){
    int t;
    cin >> t;
    int iz=1;
    int der=0;
    ans[0]=0;
    ll last=0;
    ll jump=0;
    for (int i = 1; i < 2024; ++i) {
        ll r = (i*(i+1))/2;
        ll l = 1 + ((i*(i-1))/2);
        ll p = l;
        while(p<=r){
            ans[p]=(p*p);
            int ts = 0;
            if (p-iz>=last){
                ans[p]+=ans[p-iz];
                ts++;
            }
            if (p-der<l){
                ans[p]+=ans[p-der];
                ts++;
            }
            if(ts==2){
                ans[p]-=ans[p-jump];
            }
            p++;
        }
        iz++;
        der++;
        last=l;
        jump+=2;
    }

    while(t--){
        ll n;
        cin >> n;
        cout << ans[n]<<'\n';
    }
}