#include <bits/stdc++.h>
#define ll long long
using namespace std;

const int N = 3 + (1e6);
ll pre[N];

int main(){
    int t;
    cin >> t;
    while(t--){
        int n,k;
        cin >> n >> k;
        string a,b;
        cin >> a >> b;
        int va[26];
        int vb[26];
        for (int i = 0; i < 26; ++i) {
            va[i]=0;
            vb[i]=0;
        }
        for (int i = 0; i < n; ++i) {
            va[a[i]-'a']++;
            vb[b[i]-'a']++;
        }
        bool ans=true;
        for (int i = 0; i < 26; ++i) {
            if (i==25){
                if (va[i]!=vb[i]) ans=false;
                break;
            }
            if (vb[i]>va[i]){
                ans=false;
                break;
            }else{
                if ((va[i]-vb[i]) % k == 0){
                    va[i+1]+= va[i]-vb[i];
                }

            }
        }
        if (ans) cout << "YES\n";
        else cout << "NO\n";
    }
}