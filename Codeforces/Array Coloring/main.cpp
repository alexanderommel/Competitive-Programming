#include <bits/stdc++.h>
#define ll long long
using namespace std;

const int th = 40001;

int main(){
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        int c=0;
        for (int i = 0; i < n; ++i) {
            ll nm;
            cin >> nm;
            if (nm%2!=0) c++;
        }
        if (c%2==0){
            cout <<"YES\n";
        }else{
            cout <<"NO\n";
        }
    }
}