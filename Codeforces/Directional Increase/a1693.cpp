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

typedef std::pair<ll,ll> mypair;
bool my_comparator ( const mypair& l, const mypair& r){
    return l.first > r.first;
}

int main(){
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        vll a;
        fr(0,n,i){
            ll ai;
            cin >> ai;
            a.pb(ai);
        }
        bool start=false;
        bool ans=true;
        ll current=0;
        fri(n-1,0,i){
            if(i==0 && current!=a[0]){
                ans=false;
                break;
            }
            if (a[i]!=0 && !start){
                start=true;
            }
            if (start){
                //cout << "comparing: " << a[i] << " , " << current << '\n';
                if (a[i]==current){
                    current=1;
                    continue;
                }
                if (a[i]>current){
                    ans= false;
                    break;
                } else{
                    ll diff = abs(a[i]-current);
                    current = diff;
                }
            }

        }
        if (ans){
            cout << "Yes" << '\n';
        }else{
            cout << "No" << '\n';
        }

    }
    return 0;
}
