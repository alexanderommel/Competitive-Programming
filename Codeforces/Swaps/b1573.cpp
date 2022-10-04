#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
#define pb push_back
#define ff(size) for (int i = 0; i < size; i++)
#define ll long long
#define vll vector<ll>
#define vllin(vec,n) ff(n){ll x; cin>>x; vec.pb(x);}
#define fr(size, i) for (int i=0; i<size; i++)

using namespace std;

void sol(int n, vll a, vll b){
    map<ll,ll> positionsA, positionsB;
    fr(n,i){
        positionsA[a[i]]=i;
        positionsB[b[i]]=i;
    }
    std::sort(a.begin(), a.end());
    std::sort(b.begin(), b.end());
    ll minimumSteps = LONG_LONG_MAX;
    ll minimumPos = LONG_LONG_MAX;
    fr(n,k){
        minimumPos = min(minimumPos,positionsA[a[k]]);
        ll dist =positionsB[b[k]] + minimumPos;
        minimumSteps = min(minimumSteps,dist);
    }
    cout << minimumSteps << endl;
}

int main(){
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        vll a,b;
        vllin(a,n);
        vllin(b,n);
        sol(n,a,b);
    }
}
