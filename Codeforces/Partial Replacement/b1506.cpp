#include <iostream>
#include <string>
#include <algorithm>
#define fr(size, i) for (int i=0; i<size; i++)
#define len(arr) arr.size()
#define frs(siz, init, j) for (int j=init; j<siz; j++)
using namespace std;

void sol(int n, int k, string s){
    int numXPossible=0;
    fr(len(s),i){
        if (s[i]=='*')
            numXPossible++;
    }
    if (numXPossible==1){
        cout << 1 << endl;
        return;
    }
    int FIRST_OCC_IDX=n+1;
    int LAST_OCC_IDX=n+1;
    fr(len(s),i){
        if(s[i]=='*'){
            if (FIRST_OCC_IDX==n+1){
                FIRST_OCC_IDX=i;
            }else{
                LAST_OCC_IDX=i;
            }
        }
    }
    if (LAST_OCC_IDX-FIRST_OCC_IDX<=k){
        cout << 2 << endl;
        return;
    }
    int CURRENT_ADDITION=FIRST_OCC_IDX;
    int LAST_ADDITION;
    int steps=2;
    frs(LAST_OCC_IDX+1,FIRST_OCC_IDX+1,j){
        if (s[j]=='.')
            continue;
        int distance = j-CURRENT_ADDITION;
        if (distance>k){
            CURRENT_ADDITION = LAST_ADDITION;
            steps++;
        }
        LAST_ADDITION = j;
    }
    cout << steps<< endl;
}

int main(){
    int t;
    cin >> t;
    while(t--){
        int n,k;
        cin >> n;
        cin >> k;
        string s;
        cin >> s;
        sol(n,k,s);
    }
}