#include <bits/stdc++.h>
#define pb push_back
#define vi vector<int>
#define ll long long
#define vll vector<long long>
#define pll pair<ll,ll>
using namespace std;
typedef std::tuple<int,int,int> mytuple;

bool comparador_descendente_pair ( const mytuple& l, const mytuple& r){ return get<0>(l) > get<0>(r); }


int main(){
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        if(n==1){
            cout << 1 <<'\n';
            continue;
        }
        if(n%2!=0){
            cout << -1 <<'\n';
            continue;
        }
        cout << n <<" ";
        for(int i=2;i<=n;i++){
            if (i%2==0){
                cout << n - (i-1) <<" ";
            }else{
                cout << n - (n-i+1) << " ";
            }
        }
        cout << '\n';
    }
}