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
        map<char,int> mp;
        for(int i=0;i<s.size();i++){
            mp[s[i]]++;
        }
        int ans=0;
        for(auto par: mp){
            if(par.second>=2) ans++;
        }
        if(ans>=2){
            cout << "YES\n";
        }else{
            cout << "NO\n";
        }
    }
}