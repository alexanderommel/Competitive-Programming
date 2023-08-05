#include <bits/stdc++.h>
#define ll long long
using namespace std;

const int N = 3 + (1e6);
ll pre[N];

int main(){
    int t;
    cin >> t;
    while(t--){
        string s;
        cin >> s;
        int n = s.size();
        map<int,int> used;
        int lp=0;
        int rp=0;
        int last = s[0]-'0';
        string ans="";
        while (rp<n){
            //cout << "last: "<<last<<'\n';
            int nm = s[rp]-'0';
            if (last%2==nm%2){
                last = nm;
            }else{
                while(lp<rp){
                    if (used.count(lp)>0){
                        lp++;
                        continue;
                    }
                    if ((s[lp]-'0')<=(s[rp]-'0')){
                        ans+= s[lp];
                    }else{
                        used[rp]++;
                        ans+= s[rp];
                        break;
                    }
                    lp++;
                }
                if (lp==rp){
                    last = nm;
                }
            }
            rp++;
        }
        for (int i = lp; i < n; ++i) {
            if (used.count(i)<1){
                ans+=s[i];
            }
        }
        cout << ans <<'\n';
    }
}