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
        int suma = (n*(n+1))/2;
        int sobra = (suma%n);
        for(int i=1;i<=n;i++){
            if(i==1){
                cout << sobra + 1 <<" ";
            }else{
                cout << i <<" ";
            }
         }
        cout << '\n';
    }
}