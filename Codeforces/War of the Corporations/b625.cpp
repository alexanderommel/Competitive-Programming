#include <bits/stdc++.h>
#define pb push_back
#define frs(siz, init, j) for (int j=init; j<siz; j++)
#define len(arr) arr.size()
using namespace std;

int main(){
    string s,t;
    cin >> s >> t;
    int i=0;
    int n=len(s);
    int k=len(t);
    if (k>n){
        cout << 0 << endl;
        return 0;
    }
    int lastending=INT_MIN;
    int steps=0;
    while(i<n-k+1){
        string substr;
        frs(k+i,i,j){
            substr.pb(s[j]);
        }
        if (substr==t){
            if (i<=lastending){
                i = lastending;
                steps--;
            }else{
                lastending = i+k-1;
            }
            steps++;
        }
        i++;
    }
    cout << steps << endl;
    return 0;
}
