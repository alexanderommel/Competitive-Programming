#include <bits/stdc++.h>
#define ll long long
using namespace std;

const ll L=1;
const ll R = 1e13 +1;

int main(){
    int t;
    cin >> t;
    while(t--){
        int n,k;
        cin >> n >> k;
        vector<pair<int,int>> a(n);
        for (int i = 0; i < n; ++i) {
            int nm;
            cin >> nm;
            a[i]={nm,i};
        }
        std::sort(a.begin(), a.end());
        int l=1;
        int r=k;
        int ans=-1;
        vector<pair<int,int>> res;
        while(l<=r){
            int x = (l+r)/2;
            vector<pair<int,int>> b(n);
            map<int,int> f;
            int z=1;
            int last=-1;
            int repeat = 0;
            int loc=0;
            for (int i = 0; i < n; ++i) {


                if(a[i].first==last){
                    if(repeat==x){
                        b[i]={a[i].second,0};
                        continue;
                    }else{
                        repeat++;
                        b[i]={a[i].second,z};
                        f[z]++;
                        loc++;
                    }
                }else{
                    repeat=1;
                    b[i]={a[i].second,z};
                    f[z]++;
                    loc++;
                }
                z++;
                if (z>x) z=1;
                last = a[i].first;
            }

            int minim = n+1;
            for(auto p: f){
                minim = min(minim,p.second);
            }
            f[0]=-1;

            for (int i = 0; i < n; ++i) {
                if (f[b[i].second]>minim){
                    f[b[i].second]--;
                    b[i].second = 0;
                    loc--;
                }
            }

            if(loc>=ans){
                l = x +1;
                res=b;
            }else{
                r = x - 1;
            }
        }
        std::sort(res.begin(), res.end());
        for (int i = 0; i < n; ++i) {
            cout << res[i].second << " ";
        }
        cout <<'\n';
    }
}
