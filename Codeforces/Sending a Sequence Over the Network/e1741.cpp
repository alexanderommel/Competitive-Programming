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
const int N=2e5+10;
int b[N];
vi v[N];
int memo[N];

bool dp(int x){
    if (x==0){
        memo[0]=true;
        return true;
    }
    if (x<=-1){
        return false;
    }
    if (memo[x]!=-5){
        return memo[x];
    }
    bool ans=false;
    if (x-b[x]-1>=0){
        if (memo[x-b[x]-1]!=-5){
            ans |= (memo[x-b[x]-1] == 1);
        }else{
            bool ts = dp(x-b[x]-1);
            memo[x-b[x]-1] = (ts)?1:0;
            ans|= (memo[x - b[x] - 1] == 1);
        }
    }
    for(auto left:v[x]){
        bool tsl = dp(left-1);
        ans|= tsl;
    }
    memo[x]=(ans?1:0);
    return (memo[x] == 1);
}

int main(){

    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        memo[0]=-5;
        fr(1,n+1,bb){
            v[bb].clear();
        }
        fr(1,n+1,i){
            cin >> b[i];
            memo[i]=-5;
            if (i+b[i]<=n){
                v[i+b[i]].pb(i);
            }
        }
        bool ans=false;
        if (n>1){
            ans = dp(n);
        }
        cout << (ans?"YES":"NO") << '\n';
    }
}