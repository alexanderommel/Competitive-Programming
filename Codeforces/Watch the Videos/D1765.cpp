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

    int n,m;
    cin >> n >> m;
    vll a;
    vllin(a,n);
    int l=0;
    int r=n-1;
    std::sort(a.begin(), a.end());
    ll ANS=0;
    while(l<=r){
        if (l==r){
            ANS+=(1+a[r]);
            break;
        }
        int diff = m - a[r];
        if  (a[l]<=diff){
            ANS+=a[r];
            ANS+=a[l];
            l++;
            if (l==r){
                ANS++;
                break;
            }
            r--;
        }else{
            ANS+=(1+a[r]);
            r--;
        }
    }
    cout << ANS;
    return 0;
}