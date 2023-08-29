#include <bits/stdc++.h>
#define ll long long
using namespace std;

const int th = 40001;

int main(){
    int t;
    cin >> t;
    while(t--){
        string s;
        cin >> s;
        int n = s.size();
        map<int,int> f;
        for (int i = 0; i < n; ++i) {
            f[s[i]]++;
        }
        int mx = 0;
        char winn;
        for(auto p: f){
            if (p.second>=mx){
                winn = p.first;
                mx = p.second;
            }
        }
        char gg;
        if (winn=='R') gg='P';
        if (winn=='S') gg='R';
        if (winn=='P') gg='S';
        for (int i = 0; i < n; ++i) {
            cout << gg;
        }
        cout << '\n';
    }
}