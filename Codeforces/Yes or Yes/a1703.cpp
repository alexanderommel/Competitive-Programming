#include <iostream>
#include <utility>
#include <vector>
#include <string>
#include <algorithm>
#define fr(size, i) for (int i=0; i<size; i++)
#define vi vector<int>
#define pb push_back
#define frs(size,inits,i) for (int i=inits; i<size; i++)
#define len(arr) arr.size()
using namespace std;


void sol(string s){
    int ok=0;
    fr(len(s),i){
        if (i==0 && toupper(s[i])=='Y'){
            ok+=1;
        }
        if (i==1 && toupper(s[i])=='E'){
            ok+=1;
        }
        if (i==2 && toupper(s[i])=='S'){
            ok+=1;
        }
    }
    if (ok==3){
        cout << "YES" << endl;
    }else{
        cout << "NO" << endl;
    }

}

int main(){
    int t;
    cin >> t;
    while(t--){
        string s;
        cin >> s;
        sol(s);
    }
    return 0;
}