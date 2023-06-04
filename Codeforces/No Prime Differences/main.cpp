#include <bits/stdc++.h>
#define pb push_back
#define vi vector<int>
#define ll long long
#define vll vector<long long>
#define pll pair<ll,ll>
using namespace std;
typedef std::tuple<int,int,int> mytuple;

bool is_prime(int n){
    for(int i=2;i<=n/2;i++){
        if(n%i==0){
            return false;
        }
    }
    return true;
}

int main(){
    int t;
    cin >> t;
    while(t--)  {
        int n,m;
        cin >> n >> m;
        bool prime= is_prime(m);
        if(prime){
            if (n>=m){
                for (int i = 0; i < n; i+=2) {
                    for (int j = 1; j <= m; ++j) {
                        cout << j + i * m << " ";
                    }
                    cout <<'\n';
                }
                for (int i = 1; i < n; i+=2) {
                    for (int j = 1; j <= m; ++j) {
                        cout << j + i * m << " ";
                    }
                    cout << '\n';
                }
            }else{
                if(is_prime(n)){
                    for (int i = 1; i <= n; ++i) {
                        for (int j = 0; j < m; j+=2) {
                            cout << i + j*n << " ";
                        }
                        for(int j=1;j<m;j+=2){
                            cout << i + j*n <<" ";
                        }
                        cout <<'\n';
                    }
                }else{
                    for (int i = 1; i <= n; ++i) {
                        for (int j = 0; j < m; ++j) {
                            cout << i + j*n << " ";
                        }
                        cout <<'\n';
                    }
                }

            }

        }else{
            for (int i = 0; i < n; ++i) {
                for (int j = 1; j <= m; ++j) {
                    cout << j + i*m << " ";
                }
                cout << '\n';
            }
        }
    }
    return 0;
}