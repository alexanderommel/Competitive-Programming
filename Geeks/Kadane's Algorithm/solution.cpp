#include <bits/stdc++.h>
#define pb push_back
#define vi vector<int>
#define ff(size) for (int i = 0; i < size; i++)
#define viin(vec,n) ff(n){int x; cin>>x; vec.pb(x);}
#define ll long long
#define vll vector<ll>
#define vllin(vec,n) ff(n){ll x; cin>>x; vec.pb(x);}
#define fr(size, i) for (int i=0; i<size; i++)
#define fmap(map,puntero) for (auto puntero=map.begin(); puntero!=map.end(); puntero++)
#define vec_reversrt(vec) sort(vec.begin(), vec.end(), greater<>())
#define frs(siz, init, j) for (int j=init; j<siz; j++)
#define len(arr) arr.size()
using namespace std;

int sol(vi a){
    int currentSum=0;
    int maxSum=INT_MIN;
    fr(len(a),i){
        currentSum = currentSum + a[i];
        if (currentSum>=maxSum){
            maxSum = currentSum;
        }
        if (currentSum<=0){
            currentSum=0;
        }
    }
    return maxSum;
}

int main(){
    vi a = {-2,-3,4,-1,-2,1,5,-3};
    cout << sol(a) << endl;
}