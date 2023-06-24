#include <bits/stdc++.h>
#define ll long long
using namespace std;

const ll L=1;
const ll R = 1e13 +1;
const int N=2*(1e5) + 1;

int main(){
    string k="Yes";
    for (int i = 0; i < 20; ++i) {
        k.append("Yes");
    }

    int t;
    cin >> t;
    while(t--){
        string s;
        cin >> s;
        string ans="YES";
        int start=-1;
        if (s[0]=='Y'){
            start=0;
        }
        if (s[0]=='e'){
            start=1;
        }
        if (s[0]=='s'){
            start=2;
        }
        if (start==-1){
            cout <<"NO\n";
        }else{
            for (int i = start; i < s.size()+start; ++i) {
                if (s[i-start]!=k[i]){
                    ans="NO";
                    break;
                }
            }
            cout << ans<<'\n';
        }

    }
    return 0;
}