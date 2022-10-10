#include <bits/stdc++.h>
#define pb push_back
#define fr(size, i) for (int i=0; i<size; i++)
using namespace std;

bool test(string s, int d){
    int p=-1;
    fr(s.size()+1,i){
        if (i>p+d){
            return false;
        } else{
            if (i==s.size()){
                return true;
            }
        }
        if(s[i]=='R'){
            p=i;
        }
    }
    return true;
}

void sol(int n, string s){
    int L=1;
    int R=n+1;
    int d;
    vector<int> ans;
    while(L<=R){
        d = (R+L)/2;
        bool test_u = test(s,d);
        if (test_u){
            ans.pb(d);
            R = d-1;
        }else{
            L = d+1;
        }
    }
    int minimum = INT_MAX;
    fr(ans.size(),i){
        if(ans[i]<minimum){
            minimum = ans[i];
        }
    }
    cout << minimum << endl;
}

int main(){
    int n;
    cin >> n;
    fr(n,i){
        string s;
        cin >> s;
        sol(s.size(),s);
    }
}