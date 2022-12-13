#include <bits/stdc++.h>
#define pb push_back
#define vi vector<int>
#define ll long long
#define vll vector<long long>
#define fr(s,n,i) for (long long i=s; i<n; ++i)
#define fri(s,e,i) for (long long i=s; i>=e; --i)
#define len(arr) arr.size()
#define viin(vec,n) fr(0,n,i){int x; cin>>x; vec.pb(x);}
#define vllin(vec,n) fr(0,n,i){ll x; cin>>x; vec.pb(x);}
using namespace std;

int main(){
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        fri(n,1,i){
            if (n%2!=0){
                if((n+1)/2==i){
                    cout << 1 << " ";
                    continue;
                }
                if (i==1){
                    cout << (n+1)/2 << " ";
                    continue;
                }
            }
            cout << i << " ";
        }
        cout << '\n';
    }

    return 0;
}
