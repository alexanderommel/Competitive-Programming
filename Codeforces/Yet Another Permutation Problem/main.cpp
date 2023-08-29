#include <bits/stdc++.h>
#define ll long long
using namespace std;
 
int main(){
 
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        map<int,int> f;
        vector<int> ans;
        for(int i=n;i>=1;i--){
            if(f.count(i)>0) continue;
            if(i%2==0 && i/2>0){
                int kk = i;
                ans.push_back(kk);
                while(kk/2>0 && kk%2==0 ){
                    f[kk]=10;
                    f[kk/2]=10;
                    kk = kk/2;
                    ans.push_back(kk);
                }
            }
        }
        for(int i=1;i<=n;i++){
            if(f.count(i)<=0){
                ans.push_back(i);
            }
        }
        for(int i=0;i<n;i++){
            cout << ans[i]<<" ";
        }
        cout <<'\n';
    }
    
}