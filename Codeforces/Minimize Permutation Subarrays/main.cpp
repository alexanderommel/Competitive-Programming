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
        vector<int> a;
        int b,c;
        int p = 0;
        for (int i = 0; i < n; ++i) {
            int nm;
            cin >> nm;
            a.push_back(nm);
            if (nm==1){
                b=i+1;
            } else{
                if(nm==2){
                    c= i+1;
                }
            }
            if (a[p]<nm){
                p = i;
            }
        }
        p++;
        if(b<p && c<p){
            if (b>c){
                cout << b <<" "<<p<<'\n';
            }else{
                cout << c << " "<<p<<'\n';
            }  
        } else if(b>p && c>p){
            if (b>c){
                cout << c << " "<<p<<'\n';
            }else{
                cout << b <<" "<<p<<'\n';
            }
        }else{
            cout << n<< " "<<n<<'\n';
        }
    }
    return 0;
}