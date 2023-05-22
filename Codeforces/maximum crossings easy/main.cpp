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
    while(t--)  {
        int n;
        cin >> n;
        int a[n];
        for (int i = 0; i < n; ++i) {
            cin >> a[i];
        }
        int ans=0;
        for (int x = 0; x < n-1; ++x) {
            for (int y = x+1; y < n; ++y) {
                if(a[y]<=a[x]) ans++;
            }
        }
        cout << ans<<'\n';
    }
}