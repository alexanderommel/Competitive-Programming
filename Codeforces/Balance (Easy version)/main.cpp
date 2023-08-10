#include <bits/stdc++.h>
#define ll long long
using namespace std;

const int N = 3 + (1e6);
ll pre[N];

int main(){
    map<ll,int> set;
    map<ll,ll> mex;
    int t;
    cin >> t;
    while(t--){
        char q;
        cin >> q;
        ll n;
        cin >> n;
        if (q=='+'){
            set[n]++;
        }else{
            ll i=1;
            if (mex.count(n)>0){
                i+=(mex[n]/n);
            }
            while(set.count(n*i)>0){
                i++;
            }
            cout << n*i <<'\n';
            if (i>1){
                mex[n]=(n*(i-1));
            }
        }
    }
}