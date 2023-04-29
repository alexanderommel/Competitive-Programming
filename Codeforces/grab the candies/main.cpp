#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define fr(s,n,i) for (long long i=s; i<n; ++i)
bool comparador_descendente_normal ( const long long int& l, const long long int& r){ return l > r; }

int main(){
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        ll ans=0;
        ll two=0;
        for(int i=0;i<n;i++){
            ll a;
            cin >> a;
            if(a%2==0){
                ans+=a;
            }else{
                two+=a;
            }
        }
        if(ans>two){
            cout << "YES\n";
        }else{
            cout << "NO\n";
        }
    }
}