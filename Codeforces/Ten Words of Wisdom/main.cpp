#include <bits/stdc++.h>
#define ll long long
using namespace std;

const int N = 3 + (1e6);
const int Ke= 2+ (1e6);
ll prepp[N];

int main(){
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        ll ss = 0;
        ll sr = 0;
        ll sg = 0;
        for (int i = 0; i < n; ++i) {
            int a,b;
            cin >> a >> b;
            if (a<11 && b > ss){
                ss = b;
                sr = i+1;
                sg = ss;
            }else{
                sg = i;
            }
        }
        cout << sr <<'\n';
    }
}