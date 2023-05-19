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
        int pos[n+1];
        pos[0]=0;
        for(int i=0;i<n;i++){
            int nm;
            cin >> nm;
            pos[nm]=i;
            a.push_back(nm);
        }
        // buscamos el n-1
        int buscamos=n;
        if(a[0]==n){
            buscamos=n-1;
        }
        int pos_actual = pos[buscamos];
        vector<int> ans;
        if(pos_actual==n-1){
            vector<int> b = a;
            std::reverse(b.begin(), b.end());
            for (int i = 1; i<n ; ++i) {
                vector<int>c = a;
                std::reverse(c.begin(), c.end());
                std::reverse(c.begin()+i, c.end());
                for (int x = 0; x < n; ++x) {
                    if(b[x]==c[x]) continue;
                    if (c[x]>b[x]) b = c;
                    break;
                }
            }
            ans=b;
        }else{
            vector<int> b=a;
            std::reverse(b.begin(), b.end());
            int salto = n-1 - pos_actual;
            std::reverse(b.begin(), b.begin()+salto+1);
            vector<int> winner = b;
            //cout << "current winner: \n" ;
            //for (int i = 0; i < n; ++i) {
              //  cout << winner[i]<<" ";
            //}
            //cout <<'\n';
            for (int i = n-1; i >salto+1; --i) {
                vector<int> c = b;
                std::reverse(c.begin()+i, c.end());
                for(int x=0;x<n;x++){
                    if(winner[x]==c[x]) continue;
                    if (c[x]>winner[x]) winner=c;
                    break;
                }
            }
            ans=winner;
        }
        for (int i = 0; i < n; ++i) {
            cout << ans[i]<<" ";
        }
        cout <<'\n';
    }
}