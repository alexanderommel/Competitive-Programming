#include <bits/stdc++.h>
#define ll long long
using namespace std;

const int N = 3 + (1e6);
ll pre[N];

int main(){
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        int a=0;
        int b=0;
        int par=0;
        for (int i = 0; i < n; ++i) {
            string s;
            cin >> s;
            if (s.size()%2==0){
                par+=s.size();
            }
            for (int j = 0; j < s.size(); ++j) {
                if (s[j]=='0') a++;
                if (s[j]=='1') b++;
            }
        }
        int ans=n-1;
        if ((2*(a/2)) + (2*(b/2)) >=par){
            ans++;
        }
        cout << ans <<'\n';
    }
}