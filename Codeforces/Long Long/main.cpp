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
        vector<ll> a;
        for (int i = 0; i < n; ++i) {
            ll nm;
            cin >> nm;
            a.push_back(nm);
        }
        ll ng=0;
        ll ps=0;
        bool test=false;
        for (int i = 0; i < n; ++i) {
            if (a[i]>0){
                if (test){
                    ps++;
                    test=false;
                }
            }else{
                if (a[i]<0){
                    test=true;
                }
            }
            if (a[i]<0){
                ng+=(a[i]*-1);
            }else{
                ng+=a[i];
            }


        }
        if (test)   ps++;
        cout << ng << " "<<ps<<'\n';
    }
}