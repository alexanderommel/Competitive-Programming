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


ll findNum(ll N, ll K)
{
    ll rem = N % K;

    if (rem == 0)
        return N;
    else
        return N - rem;
}

int main(){
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    ll n,k,a,b;
    cin >> n >> k >> a >>b;

    ll ans= 0;
    ll ans2= (n-1)*a;

    if(k==1){
        cout << (n-1)*a;
    }else{
        while(n!=1){
            if(n<k){
                ll localAns = (n-1)*a;
                ans+=localAns;
                n=1;
            }else{
                ll divisible = findNum(n,k);
                if(divisible==1 || divisible==0){
                    ll localAns = (n-1)*a;
                    ans+=localAns;
                    n=1;
                }
                ll resto = divisible / k;
                resto = n - resto;
                if (divisible==n){
                    if (resto*a<=b){
                        ans+= (a*resto);
                        n = n / k;
                    }else{
                        ans+=b;
                        n = n / k;
                    }
                }else{
                    ans+=(n-divisible)*a;
                    n=divisible;
                }
            }

        }
        cout << min(ans,ans2);
    }

    return 0;
}