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

vector<vector<int>> memo;

int dp(string a, string b,int n,int m){
    if (n==0){
        int total=0;
        int key = m;
        while(key>0){
            total+=b[key-1]-'a'+1;
            key--;
        }
        memo[n][m]=total;
        return memo[n][m];
    }
    if (m==0){
        int total=0;
        int key = n;
        while(key>0){
            total+=a[key-1]-'a'+1;
            key--;
        }
        memo[n][m]=total;
        return memo[n][m];
    }
    if (memo[n][m]!=-1){
        return memo[n][m];
    }
    if (a[n-1]==b[m-1]){
        memo[n][m]=dp(a,b,n-1,m-1);
    }else{
        int diff = abs((a[n-1]-'a'+1)-(b[m-1]-'a'+1));
        int replace = dp(a,b,n-1,m-1)+diff;
        int cost_cut = a[n-1] - 'a' + 1;
        int cost_add = a[m-1] - 'a' + 1;
        int cut = dp(a,b,n-1,m) + cost_cut;
        int add = dp(a,b,n,m-1) + cost_add;
        int minn = min(min(replace,cut),add);
        memo[n][m] = minn;
    }
    return memo[n][m];
}

int main(){
    string a,b;
    cin >> a >> b;
    int n=a.size();
    int m=b.size();
    vector<vector<int>> c(n+1,vector<int>(m+1,-1));
    memo = c;
    //cout << 'a' - 'a';
    cout << dp(a,b,n,m);
}