#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#define pb push_back
#define fr(size, i) for (int i=0; i<size; i++)
#define len(arr) arr.size()
using namespace std;

void sol(string s){
    vector<char> memory;
    int days=0;
    fr(len(s),i){
        if (memory.empty()){
            memory.pb(s[i]);
            days++;
        }
        bool inMemory=false;
        fr(len(memory),j){
            if (s[i]==memory[j]){
                inMemory=true;
                break;
            }
        }
        if (!inMemory){
            if (len(memory)==3){
                memory.clear();
                memory.pb(s[i]);
                days++;
            }else{
                memory.pb(s[i]);
            }
        }
    }
    cout << days << endl;
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