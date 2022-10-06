#include <bits/stdc++.h>
#define pb push_back
#define vi vector<int>
#define ff(size) for (int i = 0; i < size; i++)
#define viin(vec,n) ff(n){int x; cin>>x; vec.pb(x);}
#define ll long long
#define vll vector<ll>
#define vllin(vec,n) ff(n){ll x; cin>>x; vec.pb(x);}
#define fr(size, i) for (int i=0; i<size; i++)
#define fmap(map,puntero) for (auto puntero=map.begin(); puntero!=map.end(); puntero++)
#define vec_reversrt(vec) sort(vec.begin(), vec.end(), greater<>())
#define frs(siz, init, j) for (int j=init; j<siz; j++)
#define len(arr) arr.size()
using namespace std;

void sol(string s){
    if (len(s)!=5){
        cout << "NO" << endl;
        return;
    }
    ll a=0,b=0,c=0,d=0,e=0;
    fr(len(s),i){
        fr(5,j){
            if (s[i]=='i'){
                a=1;
                break;
            }
            if (s[i]=='m'){
                b=1;
                break;
            }
            if (s[i]=='u'){
                c=1;
                break;
            }
            if (s[i]=='r'){
                d=1;
                break;
            }
            if (s[i]=='T'){
                e=1;
                break;
            }
        }
    }
    string ans="NO";
    ll sum;
    sum = a+b+c+d+e;
    if (sum==5){
        ans="YES";
    }
    cout << ans << endl;
}

int main(){
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        string s;
        cin >> s;
        sol(s);
    }
}