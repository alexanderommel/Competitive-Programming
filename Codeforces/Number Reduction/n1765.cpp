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
        string x;
        cin >> x;
        int k;
        cin >> k;
        int p=0;
        bool ignore_leading=true;
        while(k>0){
            int mp;
            int minn=INT_MAX;
            if (x.size()-p==k){
                break;
            }
            fr(p,p+k+1,i){
                if (x[i]<minn){
                    if (x[i]=='0' && ignore_leading){
                        continue;
                    }
                    mp=i;
                    minn = x[i];
                }
            }
            k-=(mp-p);
            cout << x[mp];
            p=mp+1;
            ignore_leading = false;
        }
        if (k==0 && p<=x.size()-1){
            fr(p,x.size(),i){
                cout << x[i];
            }
        }
        cout << '\n';
    }


    return 0;
}
