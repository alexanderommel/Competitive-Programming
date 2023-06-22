#include <bits/stdc++.h>
#define pb push_back
#define vi vector<int>
#define ll long long
#define vll vector<long long>
#define pll pair<ll,ll>
using namespace std;
typedef std::tuple<int,int,int> mytuple;

int main(){
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        map<int,int> f;
        map<int,int> f2;
        int last=-1;
        int d=0;
        for (int i = 0; i <= 2*n; ++i) {
            f[i]=0;
            f2[i]=0;
        }
        for (int i = 0; i < n; ++i) {
            int nm;
            cin >> nm;
            if(i!=0 && nm!=last){
                f[last]=max(f[last],d);
                d=1;
                last=nm;
            }else{
                d++;
                last = nm;
            }
        }
        if (d>0){
            f[last]=max(f[last],d);
        }
        d=0;
        last=-1;
        for (int i = 0; i < n; ++i) {
            int nm;
            cin >> nm;
            if(i!=0 && nm!=last){
                f2[last]=max(f2[last],d);
                d=1;
                last = nm;
            }else{
                d++;
                last = nm;
            }
        }
        if (d>0){
            f2[last]=max(f2[last],d);
        }
        int ans=0;
        for (int i = 0; i <= 2*n; ++i) {
            int rel =f[i]+f2[i];
            ans=max(ans,rel);
        }
        cout << ans <<'\n';
    }
}