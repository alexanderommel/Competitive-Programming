#include <bits/stdc++.h>
#define pb push_back
#define vi vector<int>
#define ll long long
#define vll vector<long long>
#define pll pair<ll,ll>
using namespace std;

int main() {

    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    int q;
    cin >> q;
    while(q--){
        int n;
        cin >> n;
        string s,t;
        cin >>s >> t;
        map<char,int> mp;
        mp['a']=0;
        mp['b']=0;
        mp['c']=0;
        for(int i=0;i<n;i++){
            mp[s[i]]++;
            mp[t[i]]--;
        }
        if (mp['a']!=0 || mp['b']!=0 || mp['c']!=0){
            cout << "NO\n";
            continue;
        }
        int p=0;
        bool ans = true;
        for(int i=0;i<n;i++){
            if (s[i]=='b'){
                continue;
            }
            bool found = false;
            while(p<n){
                if(t[p]=='b'){
                    p++;
                    continue;
                }
                if((s[i]=='a' && t[p]=='a' && p>=i) || (s[i]=='c' && t[p]=='c' && p<=i)){
                    found = true;
                }
                p++;
                break;
            }
            if(!found){
                ans= false;
                break;
            }
        }
        if(ans){
            cout << "YES\n";
        }else{
            cout << "NO\n";
        }
    }
    return 0;
}
