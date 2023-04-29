#include <bits/stdc++.h>
#define pb push_back
#define vi vector<int>
#define ll long long
#define vll vector<long long>
#define pll pair<ll,ll>
using namespace std;
typedef std::tuple<int,int,int> mytuple;

bool prime(ll n){
    if(n<2) return false;
    for(int x=2; x*x<=n;x++){
        if(n%x==0) return false;
    }
    return true;
}

map<int,int> hold;

void prime_descomposition(int n){
    for(int x=2;x*x<=n;x++){
        while(n%x==0){
            hold[x]++;
            n/=x;
        }
    }
    if (n>1){
        hold[n]++;
    }
}

int main(){
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        int a[n];
        hold.clear();
        for(int i=0;i<n;i++){
            cin >> a[i];
            if (prime(a[i])){
                hold[a[i]]++;
            }else{
                prime_descomposition(a[i]);
            }
        }
        int ans=0;
        int sobrante=0;
        for(auto par: hold){
            ans+=(par.second/2);
            sobrante+=(par.second%2);
        }
        ans+=(sobrante/3);
        cout << ans <<'\n';
    }
}