#include <bits/stdc++.h>
#define ll long long
using namespace std;

const int NNN= 101;

vector<int> adj[NNN];
vector<map<int,int>> ans(NNN);
bool mem[NNN];

int main(){
    int t;
    cin >> t;
    while(t--){
        int n,k,x;
        cin >> n >> k >> x;
        if (k==1 && x==1){
            cout << "NO\n";
            continue;
        }
        if(x==1){
            if (n%2==0){
                cout << "YES\n"<< n/2 <<'\n';
                for (int i = 1; i <= n/2 ; ++i) {
                    cout << 2 <<" ";
                }
                cout <<'\n';
            }else{
                if (k>2){
                    cout << "YES\n";
                    int siz = (n-3) / 2;
                    cout << siz + 1 <<'\n';
                    for (int i = 1; i <=siz ; ++i) {
                        cout << 2 <<" ";
                    }
                    cout << 3 <<'\n';
                }else{
                    cout << "NO\n";
                }
            }
        }else{
            cout << "YES\n" << n <<'\n';
            for (int i = 0; i < n; ++i) {
                cout << 1 <<" ";
            }
            cout <<'\n';
        }
    }
}