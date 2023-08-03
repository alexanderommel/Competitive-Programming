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
        if (n==1){
            cout << "a"<<'\n';
            continue;
        }
        if(n==2){
            cout << "ab"<<'\n';
            continue;
        }
        map<ll,int> f;
        vector<ll> nms;
        for (int i = 1; i <=n/2 ; ++i) {
            if (n%i==0){
                f[i+1]++;
                if (f[i+1]==1){
                    nms.push_back(i+1);
                }
                if (n/i!=i){
                    f[(n/i)+1]++;
                    if (f[(n/i)+1]==1){
                        nms.push_back((n/i)+1);
                    }
                }

            }
        }
        std::sort(nms.begin(), nms.end());
        f.clear();
        int lmbd=0;
        int siz=nms.size();
        for (int i = 1; i < siz; i++) {
            if (nms[i]-nms[i-1]!=1){
                lmbd=i;
                break;
            }
        }
        nms.clear();
        char ans[n];
        int step=0;
        for (int i = 0; i <=lmbd ; i++) {
            char le = 'a' + step;
            for (int j = i; j < n; j+=lmbd+1) {
                ans[j]=le;
            }
            step++;
        }
        for (int i = 0; i < n; ++i) {
            cout << ans[i];
        }
        cout <<'\n';
    }
}