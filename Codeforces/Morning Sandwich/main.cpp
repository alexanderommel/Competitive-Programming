#include <bits/stdc++.h>
#define ll long long
using namespace std;

const int N = 3 + (1e6);
const int Ke= 2+ (1e6);
ll prepp[N];
const int LM=36;

int main(){
    int t;
    cin >> t;
    while(t--){
        int b,c,h;
        cin >> b >> c >> h;
        int zero[b];
        // cout << b + b <<'\n';
        int one[b];
        int g = c + h;
        if (c + h + 1 <=b){
            ll ttt = 2*(c+h);
            cout << ttt + 1  << '\n';
        }else{
            cout  << b + b - 1 << '\n';
        }
    }
}