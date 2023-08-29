#include <bits/stdc++.h>
#define ll long long
using namespace std;

const int th = 40001;

int main(){
    int t;
    cin >> t;
    while(t--){
        string s;
        cin >> s;
        string ans = s;
        s = "0"+s;
        int n = s.size();
        for (int i = n-1; i > 0; --i) {
            if (s[i]-'0'>=5){
                int j = 1;
                if (s[i-1]-'0'==9){
                    while(s[i-j]-'0'==9){
                        s[i-j]='0';
                        j++;
                        if (i-j==0) break;
                    }
                }
                s[i]='0';
                int nuevo = s[i-j]-'0';
                nuevo++;
                s[i-j]= (char)(nuevo + '0');
                ans = s;
            }else{
                s[i]='0';
            }
        }
        if (ans[0]=='0'){
            for (int i = 1; i < ans.size(); ++i) {
                cout << ans[i];
            }
        }else{
            cout << ans;
        }
        cout <<'\n';
    }
}