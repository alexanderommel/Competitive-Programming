#include <bits/stdc++.h>
#define pb push_back
#define vi vector<int>
#define ll long long
#define vll vector<long long>
#define pll pair<ll,ll>
using namespace std;
typedef std::tuple<int,int,int> mytuple;

int main(){
    int t;
    cin >> t;
    while(t--){
        string s;
        cin >> s;
        int ans=INT_MAX;
        for (int i = 0; i < 26; ++i) {
            char l = (char)i+'a';
            int hig=0;int c=0;
            for (int j = 0; j < s.size(); ++j) {
                if (s[j]!=l){
                    c++;
                }else{
                    hig=max(hig,c);
                    c=0;
                }
            }
            hig=max(hig,c);
            int rel=0;
            while(hig>0){
                hig/=2;
                rel++;
            }
            ans=min(ans,rel)    ;
        }
        cout << ans <<'\n';
    }
}