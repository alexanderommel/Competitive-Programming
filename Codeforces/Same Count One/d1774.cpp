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
        int n,m;
        cin >> n >> m;
        int a[n][m];
        int c[n];
        int ones=0;
        fr(0,n,i){
            int local=0;
            fr(0,m,j){
                cin >> a[i][j] ;
                if(a[i][j]==1){
                    local++;
                }
            }
            ones+=local;
            c[i]=local;
        }
        int req = ones/n;
        if(req*n!=ones){
            cout << -1 << '\n';
            continue;
        }
        vector<tuple<int,int,int>> ans;
        fr(0,m,i){
            vector<int> LS;
            vector<int> HS;
            fr(0,n,j){
                if(c[j]==req)
                    continue;
                if(c[j]>req){
                    if(a[j][i]==1){
                        if(LS.size()!=0){
                            ans.pb({j,LS[LS.size()-1],i});
                            c[LS[LS.size()-1]]++;
                            LS.pop_back();
                            c[j]--;
                        }else{
                            HS.pb(j);
                        }
                    }
                }else {
                    if(a[j][i]==0){
                        if(HS.size()!=0){
                            ans.pb({j,HS[HS.size()-1],i});
                            c[HS[HS.size()-1]]--;
                            HS.pop_back();
                            c[j]++;

                        }else{
                            LS.pb(j);
                        }
                    }
                }
            }
        }

        bool okk=false;
        fr(0,n,v){
            if(c[v]!=req){
                okk=true;
            }
        }
        if(okk){
            cout << -1 << '\n';
        }else{
            cout << ans.size() << '\n';
            fr(0,ans.size(),zzz){
                cout << get<0>(ans[zzz]) + 1 << " " << get<1>(ans[zzz]) + 1 << " " << get<2>(ans[zzz]) + 1 << '\n';
            }
        }

    }
}