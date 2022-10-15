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

void sol(string s, vector<string> t){
    map<char,vll> F;

    fr(0,s.size(),i){
        F[s[i]].pb(i);
    }
    fr(0,t.size(),i){
        map<char,ll> localF;
        fr(0,t[i].size(),j){
            localF[t[i][j]]++;
        }
        ll max_index=-1;
        for(auto pair: localF){
            max_index = max(max_index,F[pair.first][pair.second-1]);
        }
        cout << max_index + 1 << '\n';
    }
}

int main(){
    int n;
    cin >> n;
    string s;
    cin >> s;
    int m;
    cin >> m;
    vector<string> t;
    fr(0,m,i){
        string ti;
        cin >> ti;
        t.pb(ti);
    }
    sol(s,t);
}