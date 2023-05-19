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
        cin >> n;
        string s;
        cin >> s;
        set<pair<char,char>> st;
        for(int i=0;i<n-1;i++){
            st.insert({s[i],s[i+1]});
        }
        cout <<st.size() <<'\n';
    }
}