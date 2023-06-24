#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main(){
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        vector<pair<ll,int>> a(n);
        for (int i = 0; i < n; ++i) {
            ll nm;
            cin >> nm;
            a[i]={nm,i};
        }
        std::sort(a.begin(), a.end());
        ll s[n+1];
        s[0]    =0;
        for (int i = 1; i <= n; ++i) {
            s[i]=s[i-1]+a[i-1].first;
        }
        vector<int> index;
        index.push_back(a[n-1].second);
        for (int i = n-1; i >0 ; --i) {
            if (a[i].first>s[i]){
                break;
            }else{
                index.push_back(a[i-1].second);
            }
        }
        cout << index.size() << '\n';
        std::sort(index.begin(), index.end());
        for (int i = 0; i < index.size(); ++i) {
            cout << index[i] + 1 <<" ";
        }
        cout << '\n';
    }
}
