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
        vi a,b;
        viin(a,n);
        viin(b,n);

        int d_min = b[0];
        int p = 0;

        fr(0,n,i){

            while(a[i]>d_min){
                p++;
                d_min = b[p];
            }
            cout << d_min - a[i] << " ";
        }

        cout << '\n';

        ll p2 = 0;

        fr(0,n,i){
            p2 = max(i,p2);
            while(b[p2]>=a[p2+1] && p2<(n-1)){
                p2++;
            }
            cout << b[p2] - a[i] << " ";

        }

        cout << '\n';

    }

    return 0;
}
