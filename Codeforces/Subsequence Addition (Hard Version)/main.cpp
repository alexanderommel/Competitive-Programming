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
        ll s[n+1];
        s[0]=0;
        for (int i = 1; i <= n; ++i) {
            s[i]=s[i-1]+a[i-1];
        }
        bool ans= true;
        for (int i = n; i >0; --i) {
            //cout << "comparing: ("<<a[i-1]<<","<<s[i-1] <<")\n";
            if (i==1){
                if (a[0]!=1){
                    ans=false;
                    break;
                }
            }else{
                if (a[i-1]>s[i-1]){
                    ans=false;
                    break;
                }
            }
        }
        if (ans){
            cout << "YES\n";
        }else{
            cout << "NO\n";
        }
    }
}