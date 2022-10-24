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

bool mycomparator( const pair<int,pair<int,int>>& l,
                   const pair<int,pair<int,int>>& r)
{ return l.first < r.first; }

int main(){
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    int t;
    cin >> t;
    while(t--){
        int n,m;
        cin >> n >> m;
        vector<vi> nv(n);
        vector<pair<int,pair<int,int>>> plain;
        fr(0,n,i){
            vi mv(m);
            fr(0,m,h){
                cin >> mv[h];
            }
            std::sort(mv.begin(), mv.end());
            nv[i]=mv;
        }
        fr(0,n,i){
            fr(0,m,j){
                plain.pb({nv[i][j],{i,j}});
            }
        }
        std::sort(plain.begin(), plain.end(),mycomparator);
        vector<pair<int,pair<int,int>>> best;
        fr(0,m,i){
            best.pb(plain[i]);
        }
        int p1=0;
        fr(0,n,row){
            int num_candidates=0;
            fr(0,m,i){
                if (best[i].second.first==row)
                    num_candidates++;
            }
            //cout <<"row " << row << " has " << num_candidates <<'\n';
            int b = m-p1;
            int p2=b;
            fr(0,m,j){
                if (p2==m){
                    p2=0;
                }
                cout << nv[row][p2] << " ";
                p2++;
            }
            cout <<'\n';
            p1+=num_candidates;
        }
    }
    return 0;
}
