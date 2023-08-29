#include <bits/stdc++.h>
#define ll long long
using namespace std;

const int th = 40001;

int main(){
    int k;
    cin >> k;
    map<ll,tuple<ll,ll,ll>> f;
    bool found=false;
    ll t,y,u,p;
    for (int i = 0; i < k; ++i) {
        int n;
        cin >> n;
        ll a[n];
        ll sum = 0;
        map<ll,int> cc;
        for (int j = 0; j < n; ++j) {
            cin >> a[j];
            sum+=a[j];
        }
        for (int j = 0; j < n; ++j) {
            cc[a[j]]++;
            if (cc[a[j]]>1) continue;
            //cout << "re: "<<sum-a[j]<<'\n';
            if (found) break;
            if (f.count(sum-a[j])>0){
                t = get<1>(f[sum-a[j]]);
                y = get<2>(f[sum-a[j]]);
                u = i;
                p = j;
                found=true;
            }else{
                f[sum-a[j]]={1,i,j};
            }
        }
    }
    if (found){
        cout << "YES\n";
        cout << t + 1 << " "<< y+1 <<'\n';
        cout << u + 1 << " "<< p+1 <<'\n';
    }else{
        cout <<"NO\n";
    }
}