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
    int n,q;
    cin >> n >> q;
    int a[n+1];
    a[0]=0;
    ll last=-1;
    int c=0;
    for (int i = 1; i <= n; ++i) {
        ll nm;
        cin >> nm;
        a[i]=a[i-1];
        if (nm>last){
            a[i]++;
            c=0;
        }else{
            c++;
            if (c==1){
                a[i]++;
            }
        }
        last = nm;
    }
    while(q--){
        int d,e;
        cin >> d >> e;
        int loc = a[e]-a[d-1];
        if (d-e==0){
            cout << 1 <<'\n';
            continue;
        }
        if (d-e==1){
            cout << 2 <<'\n';
            continue;
        }
        if (a[d]==a[d-1]){
            loc++;
        }
        if (a[d+1]==a[d]){
            loc++;
        }
        cout << loc <<'\n';
    }
}