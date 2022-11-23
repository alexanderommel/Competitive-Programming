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

    int n,k,k2;
    cin >> n >> k;
    string s;
    cin >> s;
    int lp=n-1,rp=n-1;
    int total = 0;
    int ans=0;
    k2 = k;


    while(lp>=0){
        if (s[lp]=='b'){
            while(k<=0 && rp>=lp){
                if (s[rp]=='b'){
                    k++;
                }
                total--;
                rp--;
            }
            k--;
        }
        total++;
        ans = max(ans,total);
        lp--;
    }

    lp = n -1;
    rp = n -1;
    total = 0;
    k = k2;

    while(lp>=0){
        if (s[lp]=='a'){
            while(k<=0 && rp>=lp){
                if (s[rp]=='a'){
                    k++;
                }
                total--;
                rp--;
            }
            k--;
        }
        total++;
        ans = max(ans,total);
        lp--;
    }

    cout << ans << '\n';

    return 0;
}

