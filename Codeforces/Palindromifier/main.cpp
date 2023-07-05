#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main(){
    string s;
    cin >> s;
    int n = s.length();
    cout << 3 <<'\n';
    cout << 'L' << " " << n-1<<'\n';
    cout << 'R'<<" "<< 1+(n-2)<<'\n';
    cout << 'R'<<" "<<2*n - 1 <<'\n';
}
