#include <bits/stdc++.h>
#define pb push_back
#define vi vector<int>
#define ll long long
#define vll vector<long long>
#define fr(s,n,i) for (long long i=s; i<n; ++i)
#define fri(s,e,i) for (long long i=s; i>=e; --i)
#define len(arr) arr.size()
#define viin(vec,n) fr(0,n,i){int x; cin>>x; vec.pb(x);}
#define vllin(vec,n) fr(0,n,i){ll x; cin>>x; vec.pb(x);}
using namespace std;

int main(){
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    int n;
    cin >> n;
    vi a;
    fr(0,n,i){
        int num;
        cin >> num;
        a.pb(num);
    }

    if (n<=2){
        cout << 0 << "\n";
        fr(0,n,i){
            cout << a[i] << " ";
        }
        return 0;
    }

    std::sort(a.begin(), a.end());
    int lp=0;
    int rp=0;

    vi b;
    vi c;
    vi d;
    vi e;

    int k=0;

    //cout << "vector of candidates\n";

    fr(0,(n-1)/2,i){
        b.pb(a[i]);
        //cout << a[i] << " ";
        k=i;
    }

    //cout << "\nvector of giants\n";

    fri(n-1,k+1,i){
        c.pb(a[i]);
        //cout << a[i] << " ";
    }

    std::sort(b.begin(), b.end());
    std::sort(c.begin(), c.end());

    //cout  << '\n';


    int ans=0;

    while(lp<b.size() && rp<c.size()){
        while(c[rp]<=b[lp]){
            d.pb(c[rp]);
            rp++;
            if (rp==c.size()) break;
        }
        if (rp<c.size()){
            e.pb(c[rp]);
            e.pb(b[lp]);
            lp++;
            rp++;
        }
    }

    fr(lp,b.size(),i){
        d.pb(b[i]);
    }
    fr(rp,c.size(),i){
        e.pb(c[i]);
    }

    fr(0,d.size(),i){
        e.pb(d[i]);
    }

    int iter=1;

    fr(0,e.size(),i){
        if(iter<e.size()-1){
            if (e[iter-1]>e[iter] && e[iter+1]>e[iter]) ans++;
        }
        iter+=2;
    }

    cout << ans << '\n';

    fr(0,e.size(),i){
        cout << e[i] << " ";
    }

    return 0;
}