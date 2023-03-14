#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define fr(s,n,i) for (long long i=s; i<n; ++i)

int main(){
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        priority_queue<ll> pq;
        pq.push(0);
        int n2 = n;
        ll ans = 0;
        while(n2--){
            ll nm;
            cin >> nm;
            if(nm==0){
                ans+=pq.top();
                pq.pop();
                pq.push(0);
            }else{
                pq.push(nm);
            }
        }
        cout << ans <<'\n';
    }
}