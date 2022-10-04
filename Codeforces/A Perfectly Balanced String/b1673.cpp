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
#include <map>
#define fmap(map,puntero) for (auto puntero=map.begin(); puntero!=map.end(); puntero++)
using namespace std;

void sol(string s){
    map<char, vi> freq;
    fr(len(s),i){
        freq[s[i]].pb(i);
    }
    fmap(freq,p){
        if (len(p->second)<=1){
            continue;
        }
        if (len(p->second)==len(s)){
            cout << "YES" << endl;
            return;
        }
        fr(len(p->second)-1,j){
            int k=p->second[j+1]-p->second[j];
            if (k<freq.size()){
                cout << "NO" << endl;
                return;
            }
        }
    }
    cout << "YES" << endl;
}

int main(){
    int t;
    cin >> t;
    while(t--){
        string s;
        cin >>s;
        sol(s);
    }
    return 0;
}