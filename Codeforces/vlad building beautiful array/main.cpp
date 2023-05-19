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
    cin>>t;
    while(t--){
        ll n;
        cin >> n;
        ll a[n];
        ll min_par = LONG_LONG_MAX;
        ll min_impar = LONG_LONG_MAX;
        bool found_par = false;
        bool found_impar = false;
        for(int i=0;i<n;i++){
            cin >> a[i];
            if(a[i]%2==0){
                found_par   =true;
                min_par = min(min_par,a[i]);
            }else{
                found_impar=true;
                min_impar = min(min_impar,a[i]);
            }
        }
        bool ans=true;
        // queremos pares
        for(int i=0;i<n;i++){
            if(a[i]%2!=0){
                if(found_impar){
                    if(a[i]-min_impar<=0){
                        ans=false;
                    }
                }else{
                    ans=false;
                }
            }
        }
        if(ans) {
            cout << "YES\n";
            continue;
        }
        ans=true;
        // queremos impares
        for(int i=0;i<n;i++){
            if(a[i]%2==0){
                if(found_impar){
                    if(a[i]-min_impar<=0){
                        ans=false;
                    }
                }else{
                    ans=false;
                }
            }
        }
        if (ans){
            cout <<"YES\n";
        }else{
            cout <<"NO\n";
        }
    }
}