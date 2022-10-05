#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#define pb push_back
#define vi vector<int>
#define fr(size, i) for (int i=0; i<size; i++)
#define len(arr) arr.size()
using namespace std;

vi ans;

void tree(string pair, vector<string> winners, int steps, int nextPos, string s){
    fr(len(winners),i){
        if (pair==winners[i]){
            ans.pb(steps);
            return;
        }
    }
    if (nextPos==-1){
        return;
    }
    vector<string> candidates;
    string c1 = {s[nextPos],pair[0]};
    candidates.pb(c1);
    if (pair[1]=='0' || pair[1]=='5'){
        string c2 = {s[nextPos],pair[1]};
        candidates.pb(c2);
    }
    fr(len(candidates),k){
        tree(candidates[k],winners,steps+1,nextPos-1,s);
    }
}

void sol(string s){
    int steps=0;
    string initial_pair;
    initial_pair.pb(s[len(s)-2]);
    initial_pair.pb(s[len(s)-1]);
    vector<string> winners = {"00","25","50","75"};
    tree(initial_pair,winners,steps,len(s)-3,s);
    int minn = len(s)+1;
    fr(len(ans),b){
        if (ans[b]<minn){
            minn = ans[b];
        }
    }
    ans.clear();
    cout << minn << endl;
}

int main(){
    int t;
    cin >> t;
    while(t--){
        string n;
        cin >> n;
        sol(n);
    }
}
