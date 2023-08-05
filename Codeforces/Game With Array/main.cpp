#include <bits/stdc++.h>
#define ll long long
using namespace std;

const int N = 3 + (1e6);
ll pre[N];

int main(){
    int n,s;
    cin >> n >> s;
    if (n==1 && s==1){
        cout <<"NO\n";
        return 0;
    }
    if (n==1 && s>1){
        cout << "YES\n";
        cout << s <<'\n';
        cout << 1 <<'\n';
        return 0;
    }
    for (int i = s; i >= 1; --i) {
        if (i%(n-1)==0 ){
            int k = i/(n-1);
            int l = (n-1) / 2;
            int r = l + ((n-1) % 2);
            if (k*l<=s-i-2 && k*r<=s-i-2 && s-i + (n-1)*k  == s && i+1!= s-i){
                if (i+1>s-i){
                    int g = i + 1 - (s-i);
                    int h = g/k;
                    if ((s-i + h*k)%(i+1)==0) continue;
                }
                cout << "YES\n";
                for (int j = 0; j < l; ++j) {
                    cout << k <<" ";
                }
                cout << s-i << " ";
                for (int j = 0; j < r; ++j) {
                    cout << k <<" ";
                }
                cout << '\n';
                cout  <<s-i-1<<'\n';
                return 0;
            }
        }
    }
    cout << "NO\n";
}