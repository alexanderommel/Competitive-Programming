#include <bits/stdc++.h>
#define ll long long
using namespace std;

const int N = 3 + (1e6);
ll pre[N];

int main(){
    int t;
    cin >> t;
    while(t--){
        int a,b;
        cin >> a >> b;
        if (a>1 && b>1){
            cout << min(a,b)-1 <<'\n';
            continue;
        }
        cout << a + b <<'\n';
    }
}
