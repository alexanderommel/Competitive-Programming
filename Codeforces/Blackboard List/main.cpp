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
        vector<ll> a;
        bool gone = true;
        ll b = LONG_LONG_MAX;
        ll c = LONG_LONG_MIN;
        for (int i = 0; i < n; ++i) {
            ll nm;
            cin >> nm;
            a.push_back(nm);
            if (nm<0){
                gone= false;
                b = min(b,nm);
            }else{
                c = max(c,nm);
            }
        }
        if(!gone){
            cout << b <<'\n';
        }else{
            cout << c <<'\n';
        }
    }
}