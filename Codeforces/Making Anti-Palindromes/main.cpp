#include <bits/stdc++.h>
#define ll long long
using namespace std;

int ans=INT_MAX;
string s;

ll memo[101][101][101];

int main(){
    int t;
    cin >> t;
    while(t--){
        int n,holder=0,asd=0;
        cin >> n;
        string s;
        cin >> s;
        map<int,int> f;
        for (int i = 0; i < n; ++i) f[s[i]]++;
        bool ok = true;
        for(auto p: f) if (p.second>n/2) ok = false;
        if(!ok || n%2!=0){
            cout << -1 <<'\n';
            continue;
        }
        map<int,int> h;
        for (int i = 0; i < n/2; ++i) {
            if (s[i]==s[n-i-1]){
                asd++;
                h[s[i]]++;
            }
        }
        for(auto p: h) holder = max(max(0,p.second-(asd-p.second)),holder);
        cout << (asd-holder)/2 + (asd-holder)%2 + holder <<'\n';
    }
}