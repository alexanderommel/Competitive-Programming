#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define fr(s,n,i) for (long long i=s; i<n; ++i)
#define pb push_back
#define fri(s,e,i) for (long long i=s; i>=e; --i)

int main(){

    int t;
    cin >> t;
    while(t--)  {
        int n,k;
        cin >> n >> k;
        string s;
        cin >> s;
        ll SW[n+1];
        ll SB[n+1];
        SW[0]=0;
        SB[0]=0;
        fr(1,n+1,i){
            if(s[i-1]=='W'){
                SW[i]=SW[i-1]+1;
            }else{
                SW[i]=SW[i-1];
            }
        }
        int L=1;
        ll ans = LONG_LONG_MAX;
        fr(1,n-k+2,i){
            //int bs = SB[i+k-1] - SB[i-1];
            ll ws = SW[i+k-1] - SW[i-1];
            ans = min(ans,ws);
        }
        cout << ans <<'\n';
    }

}