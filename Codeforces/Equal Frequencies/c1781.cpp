#include <bits/stdc++.h>
#define ll long long
using namespace std;

const int N = 3 + (1e6);
ll pre[N];

int main(){
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        string s;
        cin >> s;
        map<int,int> f;
        vector<pair<int,int>> h(26);
        bool mask[26];
        int ans=n+1;
        int limit;
        for (int i = 0; i < 26; ++i) {
            f[i]=0;
            h[i]={0,i};
        }
        for (int i = 0; i < n; ++i) {
            f[s[i]-'a']++;
            h[s[i]-'a'].first++;
        }
        std::sort(h.begin(), h.end());
        std::reverse(h.begin(), h.end());
        for (int i = 1; i <=26 ; ++i) {
            if (n%i==0){
                int c=0;
                int loc=0;
                bool my_mask[26];
                for (int j = 0; j < 26; ++j) {
                    my_mask[j]=false;
                }
                for(auto p: h){
                    if (c==i) break;
                    my_mask[p.second]=true;
                    if (p.first< (n/i)) loc+= (n/i) - p.first;
                    c++;
                }
                if (loc<ans){
                    ans=loc;
                    limit = n/i;
                    for (int j = 0; j < 26; ++j) {
                        mask[j]=my_mask[j];
                    }
                }
            }
        }
        vector<int> g;
        for (int i = 0; i < 26; ++i) {
            if (mask[i] && f[i]<limit){
                g.push_back(i);
            }
        }
        int p=0;
        int i=0;
        int k=ans;
        while(k>0){
            if (f[g[p]]==limit) p++;
            if (f[s[i]-'a']<=limit && mask[s[i]-'a']){
                i++;
                continue;
            }else{
                f[s[i]-'a']--;
                s[i]=char(g[p]+'a');
                f[s[i]-'a']++;
                k--;
            }
            i++;
        }
        cout << ans <<'\n';
        cout << s <<'\n';
    }
}