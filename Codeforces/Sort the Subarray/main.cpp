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

using namespace std;

int main(){
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        int l=-1;
        int r=-1;
        int a[n];
        int b[n];
        for (int i = 0; i < n; ++i) {
            cin >> a[i];
        }
        for (int i = 0; i < n; ++i) {
            cin >> b[i];
        }
        for (int i = 0; i < n; ++i) {
            if(a[i]!=b[i]){
                l=i;
                break;
            }
        }
        for (int i = n-1; i >=0 ; --i) {
            if(a[i]!=b[i]){
                r=i;
                break;
            }
        }
        if (l==-1 || r==-1){
            cout << 1 << " "<< n <<'\n';
            continue;
        }
        int test = b[l];
        for (int i = l-1; i >=0 ; --i) {
            if (b[i]<=test){
                test=b[i];
                l=i;
            }else{
                break;
            }
        }
        test = b[r];
        for (int i = r+1; i < n; ++i) {
            if (b[i]>=test){
                test = b[i];
                r=i;
            }else{
                break;
            }
        }
        cout << l+1 << " " << r+1  <<'\n';
    }
}