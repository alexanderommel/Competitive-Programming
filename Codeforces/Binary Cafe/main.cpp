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
        ll n,k;
        cin >> n >> k;
        ll lg = log2(n);
        if (lg>=k){
            cout << (int)pow(2,k)<<'\n';
        }else{
            cout << n +1 <<'\n';
        }
    }
}
