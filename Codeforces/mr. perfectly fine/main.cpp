#include <bits/stdc++.h>
#define pb push_back
#define vi vector<int>
#define ll long long
#define vll vector<long long>
#define pll pair<ll,ll>
using namespace std;
typedef std::tuple<int,int,int> mytuple;

int main(){
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        vector<ll> a;
        vector<ll> c;
        vector<ll> b;
        for(int i=0;i<n;i++){
            ll nm;
            cin >> nm;
            string s;
            cin >> s;
            int k=0;
            if (s[0]=='1' && s[1]=='1'){
                b.push_back(nm);
                continue;
            }
            if(s[0]=='1'){
                a.push_back(nm);
            }
            if(s[1]=='1'){
                c.push_back(nm);
            }
        }
        std::sort(a.begin(), a.end());
        std::sort(c.begin(), c.end());
        std::sort(b.begin(), b.end());
        ll ans=-1;
        ll local_ans=LONG_LONG_MAX;
        if (a.size()>=1 && c.size()>=1){
            ll sm = a[0]+ c[0];
            ans=123;
            local_ans=sm;
        }
        if (b.size()>=1){
            ans=123;
            local_ans = min(local_ans,b[0]);
        }
        if(ans==-1){
            cout << -1 <<'\n';
        }else{
            cout << local_ans <<'\n';
        }
    }
}