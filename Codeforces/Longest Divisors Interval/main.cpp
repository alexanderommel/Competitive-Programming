#include <bits/stdc++.h>
#define ll long long
using namespace std;

const int N = 3 + (1e6);
const int Ke= 2+ (1e6);
ll prepp[N];
const int LM=36;

int main(){
    int t;
    cin >> t;
    while(t--){
        ll n;
        cin >> n;
        ll a=0,b=0, c=0;
        bool ok=true;
        for (int i = 1; i < 10001; ++i) {
            if(n%i==0 && c<100000){
                b++;
            }else{
                b=0;
                c+=1;
            }
            if (b>a && ok){
                a = b;
                c = 0;
            }
        }
        cout << a <<'\n';
    }
}