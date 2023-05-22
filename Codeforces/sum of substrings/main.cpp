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
        ll n,k;
        cin >> n >> k;
        string s;
        cin >> s;
        int a[n];
        for (int i = 0; i < n; ++i) {
            a[i]=s[i]-'0';
        }
        int lp=-1;
        int rp=-1;
        if(a[n-1]==0){
            for (int i = n-2; i >= 0; --i) {
                if(a[i]==1){
                    rp=i;
                    break;
                }
            }
        }
        if(n-rp-1<=k && rp!=-1){
            swap(a[rp],a[n-1]);
            k-=(n-rp-1);
        }else{
            rp=-1;
        }
        if(a[0]==0){
            for (int i = 1; i < n-1; ++i) {
                if(a[i]==1 && i!=rp){
                    lp=i;
                    break;
                }
            }
        }

        if(lp<=k && lp!=-1){
            swap(a[lp],a[0]);
            k-=lp;
        }

        ll suma=0;
        for (int i = 1; i < n; ++i) {
            if(a[i-1]==0 && a[i]==0){
                suma+=0;
                continue;
            }
            if(a[i-1]==0 && a[i]==1){
                suma+=1;
                continue;
            }
            if(a[i-1]==1 && a[i]==0){
                suma+=10;
                continue;
            }
            if(a[i-1]==1 && a[i]==1){
                suma+=11;
                continue;
            }
        }


        cout << suma <<'\n';
    }
}