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
        string n;
        cin >> n;
        int s;
        cin >> s;
        n = "0000"+ n;
        ll ans=0;
        for (int x = 0; x < n.size(); ++x) {
            ans+=(n[x]-'0');
        }
        ll p=0;
        bool step=false;
        ll moves=0;
        ll pwr = 1;
        while(ans>s){

            if(n[n.size()-1-p]-'0'==0){
                p++;
                pwr*=10;
            }else{
                ll diff = 10L - (n[n.size()-1-p]-'0');
                ll decim = pwr * diff;
                moves+=decim;
                step=true;
                ans-=(10L-diff);
                ans++;
                p++;
                pwr*=10;

                while(step){
                    if(n[n.size()-1-p]-'0'==9){
                        step= true;
                        ans-=9;
                        n[n.size()-1-p]='0';
                        p++;
                        pwr*=10;
                    }else{
                        step=false;
                        int nuevo_num = n[n.size()-1-p]-'0';
                        nuevo_num+=1;
                        char remplazo = nuevo_num + '0';
                        n[n.size()-1-p]=remplazo;
                    }

                }

            }
        }
        cout << moves<<'\n';
    }
}
