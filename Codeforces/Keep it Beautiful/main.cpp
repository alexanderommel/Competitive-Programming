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
        n--;
        string ans="1";
        bool go=false;
        ll l;
        cin >> l;
        ll r = l;
        while(n--){
            ll nm;
            cin >> nm;
            if (nm<=l && nm<r && !go){
                go=true;
                r=nm;
                ans+="1";
                continue;
            }
            if (nm>=l && nm>=r && !go){
                r = nm;
                ans+="1";
                continue;
            }
            if (nm<=l && nm>=r && go){
                r = nm;
                ans+="1";
            }else{
                ans+="0";
            }
        }
        cout << ans <<'\n';
    }
}
