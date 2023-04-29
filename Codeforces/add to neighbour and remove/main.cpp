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
        int a[n];
        ll suma = 0;
        for(int i=0;i<n;i++){
            cin >> a[i];
            suma+=a[i];
        }
        int ans=0;
        for(int i=n;i>=1;i--){
            if(suma%i==0){
                ll holder=0;
                bool yes=true;
                for(int j=0;j<n;j++){
                    holder+=a[j];
                    if (holder==(suma/i)){
                        holder=0;
                    }
                    if (holder>(suma/i)){
                        yes= false;
                        break;
                    }
                }
                if (yes){
                    ans=n-i;
                    break;
                }
            }
        }
        cout << ans <<'\n';
    }
}