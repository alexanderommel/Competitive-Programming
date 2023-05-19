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
        if(n%2==0){
            cout <<"NO\n";
        }else{
            cout <<"YES\n";
            int m=2*n;
            for(int i=1;i<=n;i+=2){
                cout << i << " "<<m<<'\n';
                m--;
            }
            for(int i=2;i<=n;i+=2){
                cout << i <<" "<<m<<'\n';
                m--;
            }
        }
    }
}
