#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main(){
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        string a,b;
        cin >> a >> b;
        int last = 0;
        int last_i = -1;
        int ka=0;
        int kb=0;
        for (int i = 0; i < n; ++i) {
            if(a[i]=='1') ka++;
            if(b[i]=='1') kb++;
        }
        if(ka==n && kb==0){
            cout << "YES\n";
            cout << 1 <<'\n';
            cout << 1 << " "<<n<<'\n';
            continue;
        }
        if(ka==0 && kb==n){
            cout << "YES\n";
            cout << 3 <<'\n';
            cout << 1 << " "<<n<<'\n';
            cout << 1 << " "<<n/2<<'\n';
            cout << n/2 + 1 <<" "<<n<<'\n';
            continue;
        }
        if(ka==n && kb==n){
            cout << "YES\n";
            cout << 2 <<'\n';
            cout << 1 << " "<<n/2<<'\n';
            cout << n/2 + 1 <<" "<<n<<'\n';
            continue;
        }
        vector<pair<int,int>> ans;
        for (int i = 0; i < n; ++i) {
            if(b[i]=='0'){
                if(last==1){
                    ans.emplace_back(last_i,i-1);
                }
            }else{
                if(last==0){
                    last_i=i;
                }
            }
            last=b[i]-'0';
        }
        if (last==1){
            ans.emplace_back(last_i,n-1);
        }
        for(auto p: ans){
            for (int i = p.first; i <= p.second; ++i) {
                b[i]='0';
                if(a[i]=='0'){
                    a[i]='1';
                }else{
                    a[i]='0';
                }
            }
        }
        //cout << a <<'\n';
        //cout << b <<'\n';
        bool res=false;
        int k=0;
        for (int i = 0; i < n; ++i) {
            if(a[i]=='1') k++;
        }
        if (k==0 || k==n) res=true;
        if(res){
            cout << "YES\n";
            int sz = 0;
            vector<pair<int,int>> ps;
            for(auto p: ans){
                sz+=2;
                if (p.first+1==1){
                    ps.emplace_back(1,n);
                    ps.emplace_back(p.second+2,n);
                    continue;
                }
                if(p.first+1==n){
                    ps.emplace_back(1,n-1);
                    ps.emplace_back(1,n);
                    continue;
                }
                ps.emplace_back(1,p.second+1);
                ps.emplace_back(1,p.first);
            }
            if(k==n){
                sz++;
                ps.emplace_back(1,n);
            }
            cout << sz <<'\n';
            for(auto p: ps){
                cout << p.first << " "<<p.second<<'\n';
            }
        }else{
            cout << "NO\n";
        }
    }
}