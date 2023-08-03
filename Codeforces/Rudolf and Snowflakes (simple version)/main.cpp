#include <bits/stdc++.h>
#define ll long long
using namespace std;

const int N = 3 + (1e6);
ll pre[N];

int main(){
    int t;
    cin >> t;
    for (int i = 0; i < N; ++i) {
        pre[i]=-1;
    }
    for (int i = 2; i <= 1000; ++i) {
        ll sum=1;
        sum += i;
        sum += (i*i);
        ll fac=2;
        while(sum<N){
            pre[sum]=1;
            fac++;
            sum += pow(i,fac);
        }
    }
    while(t--){
        ll n;
        cin >> n;
        if (pre[n]==1){
            cout << "YES\n";
        }else{
            cout << "NO\n";
        }
    }
}