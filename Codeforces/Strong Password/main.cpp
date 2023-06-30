#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main(){
    int t;
    cin >> t;
    while(t--){
        string s;
        cin >> s;
        int n = s.size();
        int m;
        cin >> m;
        string l;
        cin >> l;
        string r;
        cin >> r;
        if (m>n){
            cout << "YES\n";
            continue;
        }
        int end=s.size();
        string ans="NO";
        for (int i = m-1; i >=0 ; --i) {
            if (ans=="YES"){
                break;
            }
            int a = l[i]-'0';
            int b = r[i]-'0';
            int loc=end;
            for (int j = a; j <=b ; ++j) {
                int myp=-1;
                for (int k = end-1; k >=0 ; --k) {
                    if (j==s[k]-'0'){
                        myp=k;
                        break;
                    }
                }
                loc = min(loc,myp);
                if (myp==-1){
                    ans="YES";
                    //cout << "i: "<<j<<'\n';
                    //cout << "break\n";
                    break;
                }
            }
            end = loc;
        }
        cout << ans <<'\n';
    }
}
