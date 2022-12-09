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
vll a;

int bs(ll num){
    int l=0,r=a.size()-1;
    while(l<=r){
        int x = (l+r)/2;
        if(a[x]==num){
            return x;
        }
        if(a[x]>num){
            r = x-1;
        }else{
            l=x+1;
        }
    }
}

int main(){
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    int n;
    cin >> n;
    vector<vll> towers;
    while(n--){
        int k;
        cin >> k;
        vll tw;
        while(k--){
            ll p;
            cin >> p;
            a.pb(p);
            tw.pb(p);
        }
        towers.pb(tw);
    }
    std::sort(a.begin(), a.end());
    int joins = towers.size()-1;
    int cuts = 0;
    fr(0,towers.size(),i){
        int last_index = -1;
        fr(0,towers[i].size(),j){
            int curr_index = bs(towers[i][j]);
            if (last_index!=-1 && curr_index!=last_index+1){
                cuts++;
                joins++;
            }
            last_index = curr_index;
        }
    }

    cout << cuts << " " << joins << '\n';

    return 0;
}
