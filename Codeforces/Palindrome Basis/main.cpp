#include <bits/stdc++.h>
#define ll long long
using namespace std;

const int th = 40001;
const int  k = 498;

int main(){

    vector<int> s;

    for (int i = 1; i < th; ++i) {
        string p = to_string(i);
        std::reverse(p.begin(), p.end());
        if (p==to_string(i)){
            s.push_back(i);
        }
    }

    std::sort(s.begin(), s.end());

    ll ddp[th][k];
    for (int i = 0; i < th; ++i) {
        for (int j = 0; j < k; ++j) {
            ddp[i][j]=0;
        }
    }

    for (int i = 0; i < k; ++i) {
        ddp[0][i]=1;
    }

    ll modo = 1000000007;

    for (int i = 1; i < th; ++i) {

        for (int j = 0; j <k ; ++j) {
            if (i-s[j]<0){
                ddp[i][j]=ddp[i][j-1];
            }else{
                ll cen =ddp[i][j-1];
                if(j==0){
                    cen = 0;
                }
                ddp[i][j]+= (ddp[i-s[j]][j] + cen) % modo;

            }
        }
    }

    int t;
    cin >> t;
    while(t--){
        int n;
        cin >>n;
        cout << ddp[n][k-1] <<'\n';
    }
}