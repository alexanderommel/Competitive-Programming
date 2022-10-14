#include <bits/stdc++.h>
#define ll long long
#define fr(s,n,i) for (long long i=s; i<n; ++i)
#define len(arr) arr.size()
using namespace std;

void sol(string s){
    ll last_pos[10]={-1,-1,-1,-1,-1,-1,-1,-1,-1,-1};
    fr(0,len(s),i){
        int number = s[i]-'0';
        last_pos[number]=i;
    }
    fr(0,len(s),i){
        int value = s[i]-'0';
        fr(0,10,j){
            int last = last_pos[j];
            if (last==-1){
                continue;
            }
            if (j<value && last>i){
                value++;
                if (value<=9){
                    s[i]=value+'0';
                }
                break;
            }
        }
    }
    std::sort(s.begin(), s.end());
    fr(0,len(s),i){
        cout << s[i];
    }
    cout << '\n';
}

int main(){
    int t;
    cin >> t;
    while(t--){
        string s;
        cin >> s;
        sol(s);
    }
}
