#include <bits/stdc++.h>
#define ll long long
using namespace std;

const int N = 3 + (1e6);
ll pre[N];

int main(){
    int t;
    cin >> t;
    while(t--){
        int n,x;
        cin >> n >> x;
        int a[n+1];
        for (int i = 0; i < n; ++i) {
            a[i+1]=-1;
        }
        a[1]=x;
        a[n]=1;
        if (n%x!=0){
            cout << -1 <<'\n';
            continue;
        }
        int s = x;
        int last=s;
        a[s]=n;
        int i=2;
        while(s*i<=n){
            if(n%(s*i)==0 && (s*i)%last==0){
                a[last]=(s*i);
                last = s*i;
                s=s*i;
                i=1;
            }
            i++;
        }
        a[n]=1;
        for (int i = 1; i < n+1; ++i) {
            if (a[i]==-1){
                a[i]=i;
            }
            cout << a[i]<< " ";
        }
        cout <<'\n';
    }
}