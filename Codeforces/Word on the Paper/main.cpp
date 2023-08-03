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
        string ans;
        for (int i = 0; i < 8; ++i) {
            string s;
            cin >> s;
            for (int j = 0; j < 8; ++j) {
                char lett = s[j];
                if (lett != '.'){
                    ans+=lett;
                }
            }
        }
        string ans1 = ans;
        cout << ans1 <<'\n';
    }
}