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

        bool found = false;

        fr(0,n-1,i){
            if (s[i]=='a' && s[i+1]=='a'){
                found = true;
                break;
            }
        }

        if (found){
            cout << 2 << '\n';
            continue;
        }

        if (n==2){
            cout << -1 << '\n';
            continue;
        }

        found = false;

        fr(0,n-2,i){
            if ((s[i]=='a' && s[i+1]=='c' && s[i+2]=='a') || (s[i]=='a' && s[i+1]=='b' && s[i+2]=='a')){
                found=true;
                break;
            }
        }

        if (found){
            cout << 3 << '\n';
            continue;
        }

        if (n==3){
            cout << -1 << '\n';
            continue;
        }

        found = false;

        fr(0,n-3,i){
            if ((s[i]=='a' && s[i+1]=='b'  && s[i+2]=='c' && s[i+3]=='a') || (s[i]=='a' && s[i+1]=='c'  && s[i+2]=='b'  &&  s[i+3]=='a')){
                found = true;
                break;
            }
        }

        if (found){
            cout << 4 << '\n';
            continue;
        }

        if (n<7){
            cout << -1 << '\n';
            continue;
        }

        found = false;

        fr(0,n-6,i){
            if((s[i]=='a' && s[i+1]=='b' && s[i+2]=='b' && s[i+3]=='a' && s[i+4]=='c' && s[i+5]=='c' && s[i+6]=='a') ||
                    (s[i]=='a' && s[i+1]=='c' && s[i+2]=='c' && s[i+3]=='a' && s[i+4]=='b' && s[i+5]=='b' && s[i+6]=='a')){
                found   = true;
                break;
            }
        }

        if (found){
            cout << 7 << '\n';
            continue;
        }

        cout << -1 << '\n';
    }

    return 0;
}
