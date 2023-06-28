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
    int n,m;
    cin >> n >> m;

    int G[n+1][m+1];

    fr(0,n+1,i){
        fr(0,m+1,j){
            if (i==0 || j==0){
                G[i][j]=0;
            }else{
                cin >> G[i][j];
                G[i][j]+=max(G[i-1][j-1],max(G[i-1][j],G[i][j-1]));
            }
        }
    }

    cout << G[n][m];

}