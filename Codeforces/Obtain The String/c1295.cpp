#include <bits/stdc++.h>
using namespace std;

int main(){
    int tests;
    cin >> tests;
    while(tests--)  {
        string s,t;
        cin >> s >> t;
        int n = s.size();
        vector<int> P[27];
        for(int i=0;i<n;i++)    {
            P[s[i]-'a'].push_back(i+1);
        }
        bool no_ans = false;
        for(int i=0;i<t.size();++i){
            if(P[t[i]-'a'].size()<1){
                no_ans = true;
                break;
            }
        }
        if(no_ans){
            cout << -1 <<'\n';
            continue;
        }
        n = t.size();
        int dp[n+1];
        dp[0]=0;
        int ans=1;
        for(int i=1;i<=n;++i){
            int test = dp[i-1];
            int l=0;
            int r=P[t[i-1]-'a'].size()-1;
            int x;
            while(l<=r){
                x = (l+r)/2;
                //cout << "trying position: "<<P[t[i-1]-'a'][x]<<'\n';
                if(P[t[i-1]-'a'][x]>test){
                    r = x-1;
                }else{
                    l = x+1;
                }
            }
            if(P[t[i-1]-'a'][x]<=test && x<P[t[i-1]-'a'].size()-1){
                x++;
            }
            //cout << "found in position_ "<<P[t[i-1]-'a'][x]<<'\n';
            if(P[t[i-1]-'a'][x]<=test){
                ans++;
                dp[i]=P[t[i-1]-'a'][0];
                //cout << "saving position: "<<P[t[i-1]-'a'][0]<<'\n';
            }else{
                dp[i]=P[t[i-1]-'a'][x];
            }
        }
        cout << ans << '\n';
    }
}