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
        string s;
        cin >> s;
        int n = s.length();
        vi poss;

        int i=0;
        while(i<n){
            int pos=-1;
            if(i<=n-3){
                string th;
                th.pb(s[i]);
                th.pb(s[i+1]);
                th.pb(s[i+2]);
                if(th=="one" || th=="two"){
                    pos = i+2;
                }
            }
            if(i<=n-5){
                string th;
                th.pb(s[i]);
                th.pb(s[i+1]);
                th.pb(s[i+2]);
                th.pb(s[i+3]);
                th.pb(s[i+4]);
                if(th=="twone"){
                    pos = i+3;
                }
            }
            if(pos!=-1){
                poss.pb(pos);
                i+=3;
            }else{
                i++;
            }
        }

        if(poss.empty()){
            cout << 0 << '\n'<<""<<'\n';
        }else{
            cout << poss.size() << '\n';
            fr(0,poss.size(),i){
                cout << poss[i] << " ";
            }
            cout << '\n';
        }

    }

}