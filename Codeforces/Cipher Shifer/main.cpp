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
        string a;
        a=s[0];
        char b=s[0];
        for (int i = 1; i < n-1; ++i) {
            if (b==s[i]){
                i++;
                b=s[i];
                a+=b;
            }
        }
        cout << a<<'\n';
    }
}