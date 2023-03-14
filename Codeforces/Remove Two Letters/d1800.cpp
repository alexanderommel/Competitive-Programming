#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define fr(s,n,i) for (long long i=s; i<n; ++i)

int main(){
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        string s;
        cin >> s;
        int ans=n-1;
        for(int i=0;i<n-2;i++){
            if(s[i]==s[i+2]){
                ans--;
            }
        }
        cout << ans <<'\n';
    }
}