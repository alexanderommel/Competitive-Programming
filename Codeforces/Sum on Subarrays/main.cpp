#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main(){
    int t;
    cin >> t;
    while(t--){
        int n,k;
        cin >> n >> k;
        int negs = ((n*(n+1))/2) - k;
        if (negs==0){
            for (int i = 0; i < n; ++i) {
                cout << 1 <<" ";
            }
            cout << '\n';
            continue;
        }
        if (k==0){
            for (int i = 0; i < n; ++i) {
                cout << -1 <<" ";
            }
            cout << '\n';
            continue;
        }
        int cut=1;
        for (int i = 1; i <= 31; ++i) {
            int total1 = (i*(i+1))/2;
            int total2 = ((i+1)*(i+2))/2;
            if (negs>=total1 && negs<total2){
                cut=i;
                break;
            }
        }
        int remainder = negs-((cut*(cut+1))/2);
        remainder = 1 + cut - remainder;
        int lim1=1;
        int lim2=1;
        for (int i = 2; i <= cut+2; ++i) {
            if (i<=remainder){
                lim1+=i;
            }
            lim2+=i;
        }
        for (int i = cut; i >=1 ; --i) {
            cout <<  -1 * (i+1) << " ";
        }
        if (remainder!=(cut+1)){
            cut++;
            cout << lim1 << " ";
        }
        for (int i = cut+1; i <=n ; ++i) {
            cout << 500 << " ";
        }
        cout << '\n';
    }
}