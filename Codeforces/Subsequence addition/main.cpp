#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define fr(s,n,i) for (long long i=s; i<n; ++i)
bool comparador_descendente_normal ( const long long int& l, const long long int& r){ return l > r; }

int main(){
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        vector<ll> b;
        for(int i=0;i<n;i++){
            ll a;
            cin >> a;
            b.push_back(a);
        }
        std::sort(b.begin(), b.end(), comparador_descendente_normal);
        bool ans=true;
        int p=0;
        while(p<n-1 && ans){
            ll curr = b[p];
            for(int j=p+1;j<n;j++){
                if(b[j]<=curr){
                    curr-=b[j];
                }
                if(curr==0){
                    break;
                }
            }
            if(curr!=0){
                ans=false;
            }
            p++;
        }
        if(ans && b[p]==1){
            cout << "YES\n";
        }else{
            cout << "NO\n";
        }
    };
}