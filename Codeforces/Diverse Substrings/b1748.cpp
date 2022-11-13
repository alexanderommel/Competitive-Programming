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
        string s;
        cin >> s;

        ll ans=0;

        fr(1,101,i){

            if (i>n){
                continue;
            }

            map<char,int> f;
            int distinct = 0;
            int max_freq = 0;

            fr(0,10,z){
                f[to_string(z)[0]]=0;
            }

            fr(0,i,z){
                if (f[s[z]]==0){
                    distinct++;
                    f[s[z]]++;
                    if (f[s[z]]>=max_freq){
                        max_freq = f[s[z]];
                    }
                }else{
                    f[s[z]]++;
                    if (f[s[z]]>=max_freq){
                        max_freq = f[s[z]];
                    }
                }
            }

            bool ok=true;

            if (max_freq>distinct){
                ok= false;
            }

            if (ok){
                ans++;
            }

            int last_start = 0;

            fr(1,n-i+1,j){

                f[s[last_start]]--;

                if (f[s[last_start]]<=0){
                    distinct--;
                }

                if(f[s[j+i-1]]==0){
                    distinct++;
                    f[s[j+i-1]]++;
                    max_freq = max(max_freq,f[s[j]]);
                }else{
                    f[s[j+i-1]]++;
                    max_freq = max(max_freq,f[s[j]]);
                }

                last_start = j;


                bool ok=true;

                if (max_freq)

                for(auto pair: f){
                    if (pair.second>distinct){
                        ok=false;
                        break;
                    }
                }

                if (ok){
                    ans++;
                }

            }
        }

        cout << ans << '\n';
    }

    return 0;
}
