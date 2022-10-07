#include <bits/stdc++.h>
#define pb push_back
#define ff(size) for (int i = 0; i < size; i++)
#define ll long long
#define vll vector<ll>
#define vllin(vec,n) ff(n){ll x; cin>>x; vec.pb(x);}
#define fr(size, i) for (int i=0; i<size; i++)
#define frs(siz, init, j) for (int j=init; j<siz; j++)
using namespace std;

void sol(int n, vll nums){
    bool nonDecresing= true;
    fr(n-1,i){
        if (nums[i+1]<nums[i]){
            nonDecresing= false;
            break;
        }
    }
    if (nonDecresing){
        cout << 0 << endl;
        return;
    }
    ll last_optimal=0;
    ll comparer = nums[0];
    frs(n,1,i){
        if (nums[i]>=comparer){
            comparer = nums[i];
            continue;
        }
        ll optimal = comparer-nums[i];
        last_optimal = max(last_optimal,optimal);
    }
    ll steps=0;
    ll sum=0;
    fr(32,i){
        if (sum>=last_optimal){
            break;
        }
        ll curr = pow(2,i);
        sum+=curr;
        steps++;
    }
    cout << steps << endl;
}

int main(){
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        vll nums;
        vllin(nums,n);
        sol(n,nums);
    }
}