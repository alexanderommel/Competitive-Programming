#include <bits/stdc++.h>
#define pb push_back
#define vi vector<int>
#define ll long long
#define vll vector<long long>
#define pll pair<ll,ll>
using namespace std;
typedef std::tuple<int,int,int> mytuple;

bool comparador_descendente_pair ( const mytuple& l, const mytuple& r){ return get<0>(l) > get<0>(r); }

int main(){
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int t;
    cin >> t;
    while(t--){
        int n,s;
        cin >> n >> s;
        vector<mytuple> r;
        vector<int> a;
        vector<int> b;
        for(int i=0;i<n;i++){
            int ai;
            cin >> ai;
            a.push_back(ai);
        }
        for(int i=0;i<n;i++){
            int bi;
            cin >> bi;
            b.push_back(bi);
        }
        int extra=0;
        for(int i=0;i<n;i++){
            r.push_back({b[i],a[i]+extra,i});
            extra++;
        }
        std::sort(r.begin(), r.end(), comparador_descendente_pair);
        int p=0;
        bool ans=false;
        int entr = -1;
        while(p<n && ans== false){
            if (get<1>(r[p])<=s){
                ans=true;
                entr=get<2>(r[p])+1;
                break;
            }
            p++;
        }
        if(ans){
            cout << entr <<'\n';
        }else{
            cout << -1 <<'\n';
        }
    }
}