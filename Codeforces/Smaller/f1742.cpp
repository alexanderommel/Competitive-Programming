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

int main() {
    int t;
    cin >> t;
    while (t--) {
        ll q;
        cin >> q;
        ll sizeA = 1, sizeB = 1;
        bool all_yes = false;
        bool not_all_a = false;
        fr(0, q, i) {
            ll d, k;
            string x;
            cin >> d >> k >> x;
            if (all_yes) {
                cout << "YES" << '\n';
                continue;
            }
            if (d == 1) {
                if (not_all_a) {
                    cout << "NO" << '\n';
                    continue;
                }
                sizeA += k * x.size();
                fr(0, x.size(), v) {
                    if (x[v] != 'a') {
                        not_all_a = true;
                        break;
                    }
                }
                if (not_all_a) {
                    cout << "NO" << '\n';
                    continue;
                } else {
                    if (sizeA < sizeB) {
                        cout << "YES" << '\n';
                    }else{
                        cout << "NO" << '\n';
                    }
                }
            } else {
                sizeB += k * x.size();
                fr(0, x.size(), rr) {
                    if (x[rr] != 'a') {
                        all_yes = true;
                        break;
                    }
                }
                if (all_yes) {
                    cout << "YES" << '\n';
                    continue;
                } else {
                    if (sizeA < sizeB && not_all_a==false) {
                        cout << "YES" << '\n';
                    }else{
                        cout << "NO" << '\n';
                    }
                }
            }
        }
    }
    return 0;
}