#include <bits/stdc++.h>
#define ll long long
using namespace std;

const ll L=1;
const ll R = 1e13 +1;

int main(){
    int n,k;
    cin >> n >> k;
    map<int,int> f;
    bool ok=true;
    vector<pair<int,int>> a(n);
    for (int i = 0; i < n; ++i) {
        int nm;
        cin >> nm;
        f[nm]++;
        a[i]={nm,i};
        if (f[nm]>k){
            ok=false;
        }
    }
    std::sort(a.begin(), a.end());
    if (ok){
        cout << "YES\n";
        int x=1;
        vector<pair<int,int>> c(n);
        for (int i = 0; i < n; ++i) {
            //cout << a[i].second <<" - "<<x    <<'\n';
            c[i]={a[i].second,x};
            x++;
            if(x>k) x=1;
        }
        std::sort(c.begin(), c.end());
        for (int i = 0; i < n; ++i) {
            cout << c[i].second <<" ";
        }
    }else{
        cout << "NO\n";
    }
}