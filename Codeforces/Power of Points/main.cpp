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
        vector<ll> a(n);
        map<ll,int> f;
        for(int i=0;i<n;i++){
            cin >> a[i];
            f[a[i]]++;
        }
        vector<ll> b;
        for(auto p:f){
            b.push_back(p.first);
        }
        sort(b.begin(),b.end());
        int m=b.size();
        vector<ll> local(m);
        vector<ll> local2(m);
        local2[m-1]=n;
        local[0]=n;
        int fac = f[b[0]];
        int fac2 = f[b[m-1]];
        for(int j=1;j<m;j++){
            local[j]=(n-fac)*(b[j]-b[j-1]);
            fac+=f[b[j]];
            local2[m-j-1]=(n-fac2)*(b[m-j]-b[m-j-1]);
            fac2+=f[b[m-j-1]];
        }
        ll s1[m+1];
        s1[0]=0;
        ll s2[m+1];
        s2[0]=0;
        int j =1;
        for(int i=m-1;i>=0;i--){
            s1[j]=s1[j-1]+local[i];
            s2[j]=s2[j-1]+local2[j-1];
            j++;
        }
        map<ll,ll> ans;
        for(int i=0;i<n;i++){
            ans[a[i]]==-1;
        }
        int xx=0;
        int yy=m-1;
        for(int i=0;i<m;i++){
            ans[b[i]]=n+s1[yy]+s2[xx];
            xx++;
            yy--;
        }
        for(int i=0;i<n;i++){
            cout << ans[a[i]] << " ";
        }
    
        cout << '\n';
    }
    
}