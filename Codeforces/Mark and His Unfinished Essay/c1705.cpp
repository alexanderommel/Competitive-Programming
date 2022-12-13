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
    cin >> t ;
    while(t--){
        ll n,c,q;
        cin >> n >> c >> q;
        string s;
        cin >> s;
        vector<pair<pair<ll,ll>,pair<ll,ll>>> log;
        log.pb({{1,n},{1,n}});
        fr(0,c,i){
            ll l,r;
            cin >> l >> r;
            ll lp=-1,rp=-1;
            fr(0,log.size(),j){
                if (lp!=-1 && rp!=-1){
                    break;
                }
                if (log[j].first.first<=l){
                    lp=j;
                }
                if (log[j].first.second>=r){
                    rp=j;
                }
            }

            ll steps_left = l-log[lp].first.first+log[lp].second.first;
            ll steps_right = r-log[rp].first.first+log[lp].second.first;
            ll letter_i = steps_left%n;
            ll letter_d = steps_right%n;
            if (steps_left%n==0){
                letter_i=n;
            }
            if (steps_right%n==0){
                letter_d=n;
            }

            ll relative_left = log[log.size()-1].first.second+1;

            log.pb({{relative_left,relative_left+r-l},
                    {letter_i,letter_d}});

            //cout << "("<<relative_left<<","<<relative_left+r-l<<")"<<'\n';
            //cout << "("<<s[letter_i-1]<<","<<s[letter_d-1]<<")"<<'\n';
        }
        fr(0,q,z){
            ll qq;
            cin >> qq;

            fr(0,log.size(),x){
                if (log[x].first.second>=qq){
                    ll steps = qq - log[x].first.first + log[x].second.first;
                    ll letter_in  = steps%n;
                    if (steps%n==0){
                        letter_in=n;
                    }
                    cout << s[letter_in-1] << '\n';
                    break;
                }
            }
        }
    }
    return 0;
}
