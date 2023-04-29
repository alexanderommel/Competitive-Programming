#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define fr(s,n,i) for (long long i=s; i<n; ++i)
bool comparador_descendente_normal ( const long long int& l, const long long int& r){ return l > r; }

int main(){
    int t;
    cin >> t;
    while(t--){
        int a,b,c;
        cin >> a >> b >> c;
        if(a+b==c){
            cout << "+\n";
        }else{
            cout << "-\n";
        }
    }
}