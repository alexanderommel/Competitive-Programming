#include <bits/stdc++.h>
#define pb push_back
#define vi vector<int>
#define ll long long
#define vll vector<long long>
#define fr(s,n,i) for (long long i=s; i<n; ++i)
#define fri(s,e,i) for (long long i=s; i>=e; --i)
using namespace std;

int main(){
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    int t;
    cin >> t;
    while(t--){
        int n,q;
        cin >> n >> q;
        vi a(n);
        fr(0,n,i){
            cin >> a[i];
        }
        vi b(n,0);
        int c=0;
        int p=0;
        int t=1;
        while(c<n-1){
            if (a[p]>a[t]){
                b[p]++;
                t++;
            }else{
                p=t;
                b[p]++;
                t++;
            }
            c++;
        }
        int max_pos=-555;
        fr(0,n,ff){
            if (a[ff]==n){
                max_pos=ff;
                break;
            }
        }

        fr(0,q,z){
            int i,k;
            cin >> i >> k;
            i--;
            if (i==max_pos){
                if (i==0){
                    cout << k << '\n';
                    continue;
                }
                if (k>=i){
                    cout << k-i+1 << '\n';
                    continue;
                }else{
                    cout << 0 <<'\n';
                    continue;
                }
            }else{
                if (i==0){
                    cout << min(k,b[i])<< '\n';
                    continue;
                }
                if (k>=i){
                    cout << min(k-i+1,b[i]) << '\n';
                    continue;
                }else{
                    cout << 0 <<'\n';
                    continue;
                }
            }
        }
    }

    return 0;
}