#include <bits/stdc++.h>
#define pb push_back
#define vi vector<int>
#define ll long long
#define vll vector<long long>
#define pll pair<ll,ll>
using namespace std;
typedef std::tuple<int,int,int> mytuple;


#include <bits/stdc++.h>
#define pb push_back
#define vi vector<int>
#define ll long long

int main(){
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        vector<int> a;
        for (int i = 0; i < n; ++i) {
            int nm;
            cin >> nm;
            a.push_back(nm);
        }
        std::sort(a.begin(), a.end());
        int l=0;
        int ans=0;
        int r=n-1;
        int s = n/2;
        while(s>=1){
            ans+=(a[r]-a[l]);
            l++;
            r--;
            s--;
        }
        cout << ans <<'\n';
    }
}