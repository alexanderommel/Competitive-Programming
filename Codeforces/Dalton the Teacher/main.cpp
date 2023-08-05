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
        int n;
        int k=0,r=0;
        int d = 0;
        cin >> n;
        ll a[n];
        ll b[n];
        for (int i = 0; i < n; ++i) {
            cin >> a[i];
            if (a[i]==i+1 && d <= 2*n){
                k++;
                d++;
            }else{
                d=0;
            }
        }
        r += k/2;
        if (d<= 2*n && k%2!=0){
            r++;
        }
        cout << r <<'\n';
    }
}
