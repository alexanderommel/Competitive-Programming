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
        int n,k;
        cin >> n >> k;
        int a,b;
        bool ans=false;
        for(int i=1;i<=n;i++){
            a = i;
            b = n-i;
            int ress = (a*(a-1))/2 + (b*(b-1))/2;
            if (ress==k){
                ans=true;
                break;
            }
        }
        if (ans){
            cout << "YES\n";
            while(a--){
                cout << 1 <<" ";
            }
            while(b--){
                cout << -1 <<" ";
            }
            cout <<'\n';
        }else{
            cout << "NO\n";
        }
    }
}