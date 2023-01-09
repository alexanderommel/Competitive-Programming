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
        int n,l,r;
        cin >> n >> l >> r;
        vector<pair<int,int>> c;
        fr(0,n+1,i){
            c.pb({0,0});
        }
        fr(0,n,i){
            int v;
            cin >> v;
            if (i<l){
                c[v].first+=1;
            }else{
                c[v].second+=1;
            }
        }
        // remove good pairs
        fr(1,n+1,i){
            int NA = min(c[i].first,c[i].second);
            l-=NA;
            r-=NA;
            c[i].first-=NA;
            c[i].second-=NA;

        }
        if (l<r){
            int temp;
            fr(1,n+1,i){
                temp = c[i].first;
                c[i].first = c[i].second;
                c[i].second = temp;
            }
            temp = l;
            l = r;
            r = temp;
        }
        // count left even and odds
        int ANS=0;
        int le=0,lo=0;
        fr(1,n+1,i){
            if (c[i].first+c[i].second==0){
                continue;
            }
            le+=(2*(c[i].first/2));
            lo+=(c[i].first%2);
        }
        // operate
        int lw = min(lo,r);
        lo-=lw;
        r-=lw;
        int remm = le + r;
        ANS+=(remm/2);
        ANS+=lw;
        ANS+=(lo);
        cout << ANS << '\n';

    }

    return 0;
}
