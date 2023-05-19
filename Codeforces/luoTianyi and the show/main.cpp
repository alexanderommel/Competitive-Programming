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
        int n,m;
        cin >> n >> m;
        vector<int> a;
        map<int,int> mp;
        mp[-1]=0;
        mp[-2]=0;
        for(int i=0;i<n;i++){
            int nm;
            cin >> nm;
            mp[nm]++;
        }
        for(auto par: mp){
            if (par.first>0){
                a.push_back(par.first);
            }
        }
        std::sort(a.begin(), a.end());
        int ans=0;
        int numeros = a.size();
        for(int i=0;i<numeros;i++){
            int posicion = a[i];
            int digitos_izquierda = i;
            int digitos_derecha = numeros - i -1;
            int left = min(mp[-1]+digitos_izquierda,posicion-1);
            int right = min(mp[-2]+digitos_derecha,m-posicion);
            int local = left + right + 1;
            ans = max(ans,local);
        }
        if(mp[-1]>0){
            mp[-1]--;
            int local = 1;
            for(int nm: a){
                if(nm<m){
                    local++;
                }
            }
            local+=mp[-1];
            local = min(local,m);
            ans = max(ans,local);
        }

        if(mp[-2]>0){
            mp[-2]--;
            int local = 1;
            for(int nm: a){
                if(nm>1){
                    local++;
                }
            }
            local+=mp[-2];
            local = min(local,m);
            ans = max(ans,local);
        }
        cout <<ans <<'\n';
    }
}