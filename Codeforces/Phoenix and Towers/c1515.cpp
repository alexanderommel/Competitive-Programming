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
        int n,m,x;
        cin >> n >> m >> x;
        vector<pair<int,int>> h(n);
        fr(0,n,i){
            int num;
            cin >> num;
            h[i]={num,i};
        }

        std::sort(h.begin(), h.end(), my_comparator);
        //std::reverse(h.begin(), h.end());

//        cout << "reordered: " << '\n';
//        fr(0,n,i){
//            cout << "first: " << h[i].first << " index: " <<  h[i].second <<'\n';
//        }

        int tw[m];
        fr(0,m,i){
            tw[i]=0;
        }

        int ans[n];

        int p=0;
        int p2=0,p3,p4;
        while(p<n){
            if(p2==m){
                p2=0;
            }
            if (p2==-1){
                p2 = m-1;
            }
            p3=p2+1;
            if (p3==m){
                p3=0;
            }
            p4=p2-1;
            if (p4==-1){
                p4=m-1;
            }
            if (tw[p2]<=tw[p3] && tw[p2]<=tw[p4]){
                tw[p2]+=h[p].first;
                ans[h[p].second]=p2;
                p++;
            }else{
                if (tw[p3]>=tw[p4]){
                    p2--;
                }else{
                    p2++;
                }
            }
        }

        int minimum = INT_MAX;

        fr(0,m,j){
            if (tw[j]<=minimum){
                minimum = tw[j];
            }
        }

        bool ok=true;
        fr(0,m,j){
            if (tw[j]>minimum+x){
                ok= false;
                break;
            }
        }

        if (ok){
            cout << "YES" << '\n';
            fr(0,n,z){
                cout << ans[z] + 1<< " ";
            }
            cout << '\n';
        }else{
            cout << "NO" << '\n';
        }


    }

    return 0;
}
