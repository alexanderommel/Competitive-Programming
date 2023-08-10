#include <bits/stdc++.h>
#define ll long long
using namespace std;

const int N = 3 + (1e6);
const int Ke= 2+ (1e6);
ll prepp[N];
const int LM=36;

int main(){
    int t;
    cin >> t;
    while(t--){
        int n,m;
        cin >> n >> m;
        string s;
        cin >> s;
        int zero[n];
        int one[n];
        for (int i = 0; i < n; ++i) {
            zero[i]=-1;
            one[i]=-1;
        }
        vector<int> o;
        vector<int> z;
        int last=1;
        for (int i = 0; i < n; ++i) {
            if (s[i]=='1' && last==0){
                o.push_back(i);
                last=1;
            }else{
                last=0;
            }
        }
        last = 0;
        for (int i = n-1; i >=0 ; --i) {
            if (s[i]=='0' && last==1){
                z.push_back(i);
                last=0;
            }else{
                last=1;
            }
        }
        int start=0;
        for (int i = 0; i < o.size(); ++i) {
            for (int j = start; j < o[i]; ++j) {
                zero[j]=o[i];
            }
            start = o[i]+1;
        }
        start=n-1;
        for (int i = 0; i < z.size(); ++i) {
            for (int j = start; j > z[i] ; --j) {
                one[j]=z[i];
            }
            start = z[i]-1;
        }
        ll ans=0;
        ll extra=0;
        map<string,int> res;
        for (int i = 0; i < m; ++i) {
            int a,b;
            cin >> a >> b;
            a--;
            b--;
            if (s[a]=='0' && s[b]=='0'){
                if (zero[a]==-1 || zero[a]>b){
                    extra=1;
                }else{
                    string rev = to_string(zero[a]) + "-" + to_string(b);
                    res[rev]++;
                    //cout << "found: "<<rev<<'\n';
                }
            }
            if (s[a]=='0' && s[b]=='1'){
                if (one[b]<zero[a]){
                    extra=1;
                }else{
                    string vv = to_string(zero[a]) + "-" + to_string(one[b]);
                    res[vv]++;
                    //cout << "found: "<<vv<<'\n';
                }
            }
            if (s[a]=='1' && s[b]=='0'){
                ans++;
                string vv = to_string(a) + "-" + to_string(b);
                res[vv]++;
                //cout << "found: "<<vv<<'\n';
            }
            if (s[a]=='1' && s[b]=='1'){
                if (one[b]==-1 || one[b]<a){
                    extra=1;
                }else{
                    ans++;
                    string vv  = to_string(a) + "-" + to_string(one[b]);
                    res[vv]++;
                    //cout << "found: "<<vv<<'\n';
                }
            }
        }
        ans = 0;
        for(auto p: res){
            ans+=1;
        }
        cout << ans + extra <<'\n';
    }
}