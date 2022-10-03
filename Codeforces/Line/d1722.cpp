#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#define ll long long
#define fr(size, i) for (ll i=0; i<size; i++)
#define vll vector<long long>
#define len(arr) arr.size()
#define pb push_back
using namespace std;

void sol(string s){
    vll values;
    ll value=0;
    fr(len(s),i){
        if (i<(len(s)/2)){
            if (s[i]=='L')
                value+=(i);
            else
                value+=(len(s)-i-1);
        }
        if (i>=(len(s)/2)){
            if (s[i]=='L')
                value+=(i);
            else
                value+=(len(s)-i-1);
        }
    }

    ll current = value;

    int control = 0;
    fr(len(s),i){
        ll p;
        if (control==0){
            p = i/2;
            if (s[p]=='L'){
                current+=((len(s)-p-1)-(p));
                values.pb(current);
            }
            control = 1;
        }else{
            p = len(s)-1-(i/2);
            if (s[p]=='R'){
                current+=((len(s)-1-(i/2))-(i/2));
                values.pb(current);
            }
            control = 0;
        }
    }

    fr(len(values),i){
        cout << values[i] << ' ';
    }
    fr(len(s)-len(values),i){
        if (len(values)==0){
            cout << current << ' ';
        }else{
            cout << values[len(values)-1] << ' ';
        }
    }
}

int main(){
    int t;
    cin >> t;
    while(t--){
        ll n;
        cin >> n;
        string s;
        cin >> s;
        sol(s);
        cout << endl;
    }
}