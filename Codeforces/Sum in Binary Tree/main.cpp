#include <bits/stdc++.h>
#define pb push_back
#define vi vector<int>
#define ll long long
#define vll vector<long long>
#define pll pair<ll,ll>
using namespace std;
typedef std::tuple<int,int,int> mytuple;


#include <bits/stdc++.h>
#define pb push_back
#define vi vector<int>
#define ll long long


int main()  {
    int t;
    cin >> t;
    while(t--){
        ll n;
        cin >> n ;
        ll ans=0;
        while(n>0){
            ans+=n;
            if(n%2==0){
                n/=2;
            }else{
                n--;
                n/=2;
            }
        }
        cout << ans <<'\n';
    }
}