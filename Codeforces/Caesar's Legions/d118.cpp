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

ll factor(int n){
    if (n==0){
        return 1;
    }
    return n*factor(n-1);
}

void sol(int a,int b,int ka,int kb){
    if (ka>a)
        ka=a;
    if(kb>b)
        kb=b;
    ll c = 0;
    while(a>0 || b>0){
        cout << "original" << '\n';
        cout << "a: " << a << " - b: " << b << '\n';
        if (a==0 && b>0){
            if (b>kb){
                cout << 0 << '\n';
                return;
            }
        }
        if(b==0 && a>0){
            if (a>ka){
                cout << 0 << '\n';
                return;
            }
        }
        int n = ka+kb;
        ll num_factor = factor(n);
        ll dec_factor = factor(ka)*factor(kb);
        ll permutations = num_factor/dec_factor;
        cout << "permutations: "  << permutations << '\n';
        c = c + permutations;
        a-=ka;
        b-=kb;
    }
    cout << c << '\n';
}

int main(){
    int a,b,ka,kb;
    cin >> a >> b >> ka >> kb;
    sol(a,b,ka,kb);
    return 0;
}