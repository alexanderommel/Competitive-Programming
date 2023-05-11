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
        int nn=0;
        string t = "codeforces";
        for(int i=0;i<10;i++){
            if(s[i]!=t[i]){
                nn++;
            }
        }
        cout << nn <<'\n';
    }
}
