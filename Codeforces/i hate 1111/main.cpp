#include <bits/stdc++.h>
#define pb push_back
#define vi vector<int>
#define ll long long
#define vll vector<long long>
#define pll pair<ll,ll>
using namespace std;
typedef std::tuple<int,int,int> mytuple;

bool ans= false;

int main(){
    int t;
    cin >> t;
    while(t--){
        ll k;
        cin >> k;
        ans=false;
        for(int i=0;i<=10000;i++){
            ll pp  = i * 111;
            if(k>=pp){
                ll sp = k - pp;
                ll sobrante  = sp/11;
                if(sobrante*11==sp){
                    ans=true;
                }
            }
        }
        if(ans){
            cout << "YES\n";
        }else{
            cout << "NO\n";
        }
    }
    return 0;
}