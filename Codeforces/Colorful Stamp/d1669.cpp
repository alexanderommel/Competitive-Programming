#include <iostream>
#include <string>
#include <algorithm>
#define fr(size, i) for (int i=0; i<size; i++)
#define len(arr) arr.size()
using namespace std;

void sol(string s){
    int ady_len=0;
    int repeatedA=0;
    int repeatedB=0;
    if (len(s)==1){
        if (s[0]=='R' || s[0]=='B'){
            cout << "NO" << endl;
            return;
        }
        cout << "YES" << endl;
        return;
    }
    fr(len(s),i){
        if (s[i]=='W'){
            if ((repeatedA==ady_len || repeatedB==ady_len) && ady_len>=1){
                cout << "NO" << endl;
                return;
            }
            repeatedA=0;
            repeatedB=0;
            ady_len = 0;
            continue;
        }
        if (s[i]=='R')
            repeatedA++;
        if (s[i]=='B')
            repeatedB++;
        ady_len++;
        if (i==len(s)-1){
            if ((repeatedA==ady_len || repeatedB==ady_len) && ady_len>=1){
                cout << "NO" << endl;
                return;
            }
        }
    }
    cout <<"YES" << endl;
}

int main(){
    int t;
    cin >> t;
    while (t--){
        int n;
        cin >> n;
        string s;
        cin >> s;
        sol(s);
    }
}