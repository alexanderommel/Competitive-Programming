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
        int n,k;
        cin >> n >> k;
        map<int,int> f;
        vi candidates;
        fr(0,n,i){
            int ai;
            cin >> ai;
            f[ai]++;
        }
        for(auto pair: f){
            if (pair.second>=k){
                candidates.pb(pair.first);
            }
        }
        std::sort(candidates.begin(), candidates.end());
        if (candidates.empty()){
            cout << -1 << '\n';
            continue;
        }
        int l=-1,r=-1;
        int lp=0,rp=0;
        int max_len = -1;
        int curr_len = 0;
        while(lp<candidates.size()){
            int step = -1;
            fr(lp,candidates.size()+1,i){
                rp = i;
                step++;
                if (rp==candidates.size()){
                    lp = rp;
                    break;
                }
                if (candidates[rp]>candidates[lp]+step){
                    curr_len = 0;
                    lp = rp;
                    break;
                }else{
                    curr_len++;
                    if (curr_len>=max_len){
                        l = lp;
                        r = rp;
                        max_len = curr_len;
                    }
                }
            }
        }
        cout << candidates[l] << " " << candidates[r] << '\n';
    }

    return 0;
}
