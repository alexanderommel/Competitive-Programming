#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#define pb push_back
#define vi vector<int>
#define ff(size) for (int i = 0; i < size; i++)
#define viin(vec,n) ff(n){int x; cin>>x; vec.pb(x);}
#define fr(size, i) for (int i=0; i<size; i++)

using namespace std;

void sol(int n,vi a, vi b){
    int INDEX_MAX=n,INDEX_ZERO=n;
    fr(n,i){
        if (a[i]>b[i]){
            cout << "NO" << endl;
            return;
        }
        if (b[i]-a[i]==0){
            INDEX_ZERO=i;
        }
    }
    int l=n-1,r=0;
    fr(n,i){
        (l==n?l=0:l=l);
        if ((b[l]>b[r]+1) && a[l]<b[l]){
            cout << "NO" << endl;
            return;
        }
        l+=1;
        r+=1;
    }
    INDEX_MAX = distance(a.begin(),max_element(a.begin(), a.end()));
    if (INDEX_ZERO==n){
        int lf=INDEX_MAX-1, rt=INDEX_MAX;
        fr(n,i){
            (lf==-1?lf=n-1:lf=lf);
            (rt==-1?rt=n-1:rt=rt);
            if (b[lf]<=a[rt]){
                a[lf]=b[lf];
                INDEX_ZERO = lf;
            }else{
                (a[lf]<a[rt]?a[lf]=a[rt]:a[lf]=a[lf]);
            }
            lf = lf-1;
            rt = rt-1;
        }
    }
    if (INDEX_ZERO!=n){
        int lf=INDEX_ZERO-1;
        int rt=INDEX_ZERO;
        fr(n,i){
            (lf==-1?lf=n-1:lf=lf);
            (rt==-1?rt=n-1:rt=rt);
            if ((b[lf]>(a[rt]+1)) && (a[lf]!=b[lf])){
                cout << "NO" << endl;
                return;
            } else{
                a[lf] = b[lf];
            }
            lf = lf-1;
            rt = rt-1;
        }
    }
    cout << "YES" << endl;
}

int main(){
    int t;
    cin >> t;
    while (t--){
        int n;
        cin >> n;
        vi a;
        vi b;
        viin(a,n);
        viin(b,n);
        sol(n,a,b);
    }
}