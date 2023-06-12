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
        int n;
        string s;
        cin >> n;
        cin >> s;
        int l=0;
        int r=0;
        int ans[n];
        vector<int> colector;
        int tt;
        int p=0;
        int res=-1;
        while(p<2 && res!=1){
            if (p==1){
                for (int i = 0; i < n; ++i) {
                    if (s[i]=='('){
                        s[i]=')';
                    }else{
                        s[i]='(';
                    }
                }
            }
            l=0;
            r=0;
            colector.clear();
            for (int i = 0; i < n; ++i) {
                ans[i]=1;
                if(s[i]=='('){
                    l++;
                    colector.push_back(i);
                }else{
                    if (l>0){
                        l--;
                        ans[colector[colector.size()-1]]=2;
                        colector.pop_back();
                        ans[i]=2;
                    }else{
                        r++;
                    }
                }
            }
            if (l==r){
                int rel = 1;
                for (int i = 0; i < n; ++i) {
                    if(i==0){
                        tt = ans[i];
                    }else{
                        if (ans[i]!=tt){
                            rel=2;
                            break;
                        }
                    }
                }
                res=rel;
            }
            p++;
        }
        if (res==-1){
            cout << -1 <<'\n';
            continue;
        }
        cout << res <<'\n';
        for (int i = 0; i < n; ++i) {
            if (res==1){
                cout << 1 <<" ";
            }else{
                cout << ans[i]<<" ";
            }
        }
        cout <<'\n';
    }
}